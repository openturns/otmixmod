from __future__ import print_function
from openturns import *
from otmixmod import *

size = 200
dim = 1

# To extract the input part of the mixture
inputIndices = Indices(dim)
inputIndices.fill(0)
# To extract the output part of the mixture
outputIndices = Indices(dim)
outputIndices.fill(dim)

model = SymbolicFunction(
    "x", "(1.0 + sign(x)) * cos(x) - (sign(x) - 1) * sin(2*x)")
dataX = Uniform().getSample(size)
print('dataX=', dataX)
dataX = dataX.sort()
dataY = model(dataX)
# For validation
dataXValid = Uniform().getSample(divmod(size, 5)[0])
dataYValid = model(dataXValid)

data = Sample(size, 2)
for i in range(size):
    data[i, 0] = dataX[i, 0]
    data[i, 1] = dataY[i, 0]

bestExpert = 0
bestCluster = 0
bestError = SpecFunc.MaxScalar
k = 2
kmax = 10
stop = False
covModel = 'Gaussian_pk_Lk_C'
while not stop:
    print("Try with", k, "cluster(s)")
    logLike = Point(0)
    labels = Indices(0)

    # Classify data
    mixture, labels, logLike = MixtureFactory(k, covModel).buildAsMixture(data)

    # Build the clusters
    print("Build the clusters")
    clusters = MixtureFactory.BuildClusters(data, labels, k)

    # Build the local meta-models
    print("Build the local experts")
    metaModels = Basis()
    for i in range(k):
        print("Expert ", i)
        # Extract the distribution of the current cluster
        distribution = mixture.getDistributionCollection()[
            i].getMarginal(inputIndices)
        # Build the local meta model using PCE
        # We use a projection strategy
        projection = ProjectionStrategy(LeastSquaresStrategy(distribution))
        # We use an Hermite chaos expansion
        basis = OrthogonalProductPolynomialFactory(
            PolynomialFamilyCollection(dim, OrthogonalUniVariatePolynomialFamily(HermiteFactory())))
        # FixedStrategy
        if k == 1:
            degree = 16
        else:
            degree = 2
        adaptive = AdaptiveStrategy(
            OrthogonalBasis(basis), EnumerateFunction().getStrataCumulatedCardinal(degree))
        algo = FunctionalChaosAlgorithm(clusters[i].getMarginal(inputIndices), clusters[
                                        i].getMarginal(outputIndices), distribution, adaptive, projection)
        algo.run()
        metaModels.add(algo.getResult().getMetaModel())

    print("Build the expert mixture")
    classifier = MixtureClassifier(mixture)
    expert = ExpertMixture(metaModels, classifier)
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
