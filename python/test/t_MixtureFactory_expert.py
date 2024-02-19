#!/usr/bin/env python

import openturns as ot
import otmixmod

size = 200
dim = 1

# To extract the input part of the mixture
inputIndices = [0]
# To extract the output part of the mixture
outputIndices = [1]

model = ot.SymbolicFunction(
    "x", "(1.0 + sign(x)) * cos(x) - (sign(x) - 1) * sin(2*x)")
dataX = ot.Uniform().getSample(size)
print('dataX=', dataX)
dataX = dataX.sort()
dataY = model(dataX)
# For validation
dataXValid = ot.Uniform().getSample(size // 5)
dataYValid = model(dataXValid)

data = dataX
data.stack(dataY)


bestExpert = 0
bestCluster = 0
bestError = ot.SpecFunc.MaxScalar
k = 2
kmax = 10
stop = False
covModel = 'Gaussian_pk_Lk_C'
while not stop:
    print("Try with", k, "cluster(s)")

    # Classify data
    mixture, labels, logLike = otmixmod.MixtureFactory(k, covModel).buildAsMixture(data)

    # Build the clusters
    print("Build the clusters")
    clusters = otmixmod.MixtureFactory.BuildClusters(data, labels, k)

    # Build the local meta-models
    print("Build the local experts")
    metaModels = ot.Basis()
    for i in range(k):
        print("Expert ", i)
        # Extract the distribution of the current cluster
        distribution = mixture.getDistributionCollection()[
            i].getMarginal(inputIndices)
        # Build the local meta model using PCE
        # We use a projection strategy
        projection = ot.ProjectionStrategy(ot.LeastSquaresStrategy(distribution))
        # We use an Hermite chaos expansion
        basis = ot.OrthogonalProductPolynomialFactory(
            ot.PolynomialFamilyCollection(dim, ot.HermiteFactory()))
        # FixedStrategy
        if k == 1:
            degree = 16
        else:
            degree = 2
        adaptive = ot.AdaptiveStrategy(
            ot.OrthogonalBasis(basis), ot.EnumerateFunction().getStrataCumulatedCardinal(degree))
        algo = ot.FunctionalChaosAlgorithm(clusters[i].getMarginal(inputIndices),
                                           clusters[i].getMarginal(outputIndices), distribution, adaptive, projection)
        algo.run()
        metaModels.add(algo.getResult().getMetaModel())

    print("Build the expert mixture")
    classifier = ot.MixtureClassifier(mixture)
    expert = ot.ExpertMixture(metaModels, classifier)
    print("Value at -1=%.6f" % expert([-1.0])[0])
    print("Value at  0=%.6f" % expert([0.0])[0])
    print("Value at  1=%.6f" % expert([1.0])[0])
    # Validation error
    print("Validation")
    print("expert input dimension=", expert.getInputDimension())
    print("validation dimension=", dataXValid.getDimension())
    dataYMeta = expert(dataXValid)
    error = 0.0
    for i in range(dataYMeta.getSize()):
        error += (dataYValid[i] - dataYMeta[i]).normSquare()
    print("k=", k, "error=%.4e" % error)
    if (error < bestError):
        bestExpert = expert
        bestCluster = k
        bestError = error

    stop = (k == kmax)
    print(k, "cluster(s) done, best=", bestCluster, "error=%.4e" % bestError)
    k += 1
