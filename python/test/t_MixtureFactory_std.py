#!/usr/bin/env python

import openturns as ot
import otmixmod

dim = 3
size = 10000
R = ot.CorrelationMatrix(dim)
# Create a collection of distribution
coll = []

for i in range(1, dim):
    R[i, i - 1] = 0.3

distribution1 = ot.Normal([-2.0] * dim, [1.2] * dim, R)
coll.append(distribution1)
for i in range(1, dim):
    R[i, i - 1] = -0.5

distribution2 = ot.Normal([2.0] * dim, [0.8] * dim, R)
coll.append(distribution2)
distribution3 = ot.Normal([-5.0] * dim, [1.4] * dim, R)
coll.append(distribution3)
distributionRef = ot.Mixture(coll)
sample = distributionRef.getSample(size)

for covarianceModel in otmixmod.MixtureFactory.GetValidCovarianceModels():
    factory = otmixmod.MixtureFactory(3, covarianceModel)
    estimatedDistribution, labels, BICLogLikelihood = factory.build(sample)
    print(covarianceModel, "PDF=%.6f" %
          estimatedDistribution.computePDF([1.7] * dim))
