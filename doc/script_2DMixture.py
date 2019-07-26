from __future__ import print_function
from openturns import *
from otmixmod import *
from openturns.viewer import View

draw = True

#####################################################################
# Create a multidimensional sample from a mixture of Normal
dim = 2
size = 20000
coll = []
R = CorrelationMatrix(dim)


# First atom
for i in range(dim-1):
    R[i,i+1] = -0.2
mean = Point(dim, -2.2)
sigma = Point(dim, 1.2)
d = Normal(mean, sigma, R)
coll.append(d)


# Second atom
R = CorrelationMatrix(dim)
for i in range(dim-1):
    R[i,i+1] = 0.1
mean = Point(dim, 2.0)
sigma = Point(dim, 0.8)
d = Normal(mean, sigma, R)
coll.append(d)


# Third atom
mean = Point( (-5.0, 5.0) )
sigma = Point(dim, 1.4)
R = CorrelationMatrix(dim)
d = Normal(mean, sigma, R)
coll.append(d)

weights = [0.5, 0.25, 0.25]

# Reference mixture
mixture = Mixture(coll, weights)

# Creation of the numerical Sample from which we will estimate
# the parameters of the mixture.
sample = mixture.getSample(size)


#####################################################################
# Creation of the mixture factory
myAtomsNumber = 3
myCovModel = 'Gaussian_pk_L_Dk_A_Dk'

bestLL = -1e100
bestMixture = Mixture()
bestNbClusters = 0
stop = False
nbClusters = 1
while not stop:
    factory = MixtureFactory(nbClusters, myCovModel)
    # Estimation of the parameters of the mixture
    estimatedDistribution, labels, logLikelihood = factory.build(sample)
    stop = logLikelihood[1] <= bestLL
    if not stop:
        bestLL = logLikelihood[1]
        bestNbClusters = nbClusters
        bestMixture = estimatedDistribution
    nbClusters += 1
print("best number of atoms=", bestNbClusters)
myAtomsNumber = bestNbClusters
estimatedDistribution = bestMixture
# Some printings to show the result
print("Covariance Model used=", myCovModel)

print("")
print("Estimated distribution:", estimatedDistribution)

# Some drawings
if draw and (sample.getDimension() == 2):
    g = estimatedDistribution.drawPDF()
    c = Cloud(sample)
    c.setColor("red")
    c.setPointStyle("bullet")
    ctmp = g.getDrawable(0)
    g.setDrawable(Drawable(c), 0)
    g.add(ctmp)
    View(g).save('testMixMod.png')

