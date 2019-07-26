
from __future__ import print_function
from openturns import *
from otmixmod import *

dim = 3
size = 10000
R = CorrelationMatrix(dim)
# Create a collection of distribution
coll = DistributionCollection(0)

for i in range(1, dim):
    R[i, i - 1] = 0.3

distribution1 = Normal(Point(dim, -2.0), Point(dim, 1.2), R)
coll.add(Distribution(distribution1))
for i in range(1, dim):
    R[i, i - 1] = -0.5

distribution2 = Normal(Point(dim, 2.0), Point(dim, 0.8), R)
coll.add(Distribution(distribution2))
distribution3 = Normal(Point(dim, -5.0), Point(dim, 1.4), R)
coll.add(Distribution(distribution3))
distributionRef = Mixture(coll)
sample = Sample(distributionRef.getSample(size))

for covarianceModel in ['Gaussian_pk_L_B', 'Gaussian_pk_L_Bk']:
    factory = MixtureFactory(3, covarianceModel)
    estimatedDistribution, labels, BICLogLikelihood = factory.build(sample)
    print(covarianceModel, "PDF=%.6f" %
          estimatedDistribution.computePDF(Point(dim, 1.7)))
