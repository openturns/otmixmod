%feature("docstring") OTMIXMOD::MixtureFactory
"Mixture inference.

Parameters
----------
atomsNumber : int
    The number of atoms
covarianceModel : str, optional
    The covariance model.
    Default is 'Gaussian_pk_Lk_C'
    See :meth:`GetValidCovarianceModels` for available models

Notes
-----
Each value of the `covarianceModel` parameter defines a specific
parametrization of the mixture of Gaussians.
See (Biernacki et al., 2006) table 1 page 290 for details on these
different parametrizations.

References
----------

- Biernacki C., Celeux G., Govaert G., Langrognet F., (2006). 
  Model-Based Cluster and Discriminant Analysis with the MIXMOD Software.
  Computational Statistics and Data Analysis, vol. 51/2, pp. 587-600.

Examples
--------
Estimate the parameters of the mixture of 2 Gaussians.

>>> import openturns as ot
>>> import otmixmod

>>> factory = otmixmod.MixtureFactory(2, 'Gaussian_pk_L_Dk_A_Dk')
>>> sample = [
...     [1.5, 0.7],
...     [0.2, -0.6],
...     [2.1, 0.1],
...     [1.2, 2.4],
...     [2.2, 0.0],
...     [-0.9, -2.1],
...     [-1.7, -0.3],
...     [0.7, 0.4],
...     [-1.2, 1.1],
...     [-0.5, -1.1],
... ]
>>> estimatedDistribution, labels, logLikelihood = factory.build(sample)
"

// ----------------------------------------------------------------------------

%feature("docstring") OTMIXMOD::MixtureFactory::buildAsMixture
"Mixture inference.

Parameters
----------
sample : :py:class:`openturns.Sample`
    Sample

Returns
-------
mixture : :py:class:`openturns.Mixture`
    Inferred distribution
"

// ----------------------------------------------------------------------------

%feature("docstring") OTMIXMOD::MixtureFactory::setSeed
"Mixmod RNG seed accessor.

Parameters
----------
seed : int
    Seed used to initialize the Mixmod RNG seed before the learning step.
    A negative seed will randomly initialize the RNG.
    The default value is 0.
"

// ----------------------------------------------------------------------------

%feature("docstring") OTMIXMOD::MixtureFactory::setAtomsNumber
"Atoms number accessor.

Parameters
----------
atomsNumber : int
    The number of atoms
"

// ----------------------------------------------------------------------------

%feature("docstring") OTMIXMOD::MixtureFactory::getAtomsNumber
"Atoms number accessor.

Returns
-------
atomsNumber : int
    The number of atoms
"

// ----------------------------------------------------------------------------

%feature("docstring") OTMIXMOD::MixtureFactory::GetValidCovarianceModels
"Available covariance models names accessor.

Returns
-------
names : :py:class:`openturns.Description`
    Valid covariance model names
    
Examples
--------
>>> import otmixmod
>>> otmixmod.MixtureFactory.GetValidCovarianceModels()[:3]
[Gaussian_p_L_I,Gaussian_p_Lk_I,Gaussian_p_L_B]
"

// ----------------------------------------------------------------------------

%feature("docstring") OTMIXMOD::MixtureFactory::BuildClusters
"Partition a given sample into nbClusters according to the given labels.

Parameters
----------
data : 2-d sequence of float
    The sample
labels : sequence of int
    The index of the class of each point in the sample
nbClusters : int
    The number of clusters in the mixture

Returns
-------
clusters : sequence of :py:class:`openturns.Sample`
    The list of samples corresponding to each class
"
