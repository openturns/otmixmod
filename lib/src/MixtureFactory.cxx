//                                               -*- C++ -*-
/**
 *  @brief Factory for MixMod distribution
 *
 *  Copyright 2005-2018 Airbus-EDF-IMACS-Phimeca
 *
 *  OTMixmod is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  OTMixmod is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with OTMixmod.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "otmixmod/MixtureFactory.hxx"

#include <openturns/Normal.hxx>
#include <openturns/Collection.hxx>
#include <openturns/Exception.hxx>
#include <openturns/Path.hxx>
#include <openturns/Os.hxx>

#include <mixmod/Clustering/ClusteringInput.h>
#include <mixmod/Clustering/ClusteringOutput.h>
#include <mixmod/Clustering/ClusteringMain.h>
#include <mixmod/Clustering/ClusteringModelOutput.h>
#include <mixmod/Kernel/IO/GaussianData.h>
#include <mixmod/Kernel/Parameter/GaussianEDDAParameter.h>
#include <mixmod/Kernel/IO/ParameterDescription.h>
#include <mixmod/Kernel/IO/LabelDescription.h>
#include <mixmod/Kernel/IO/Label.h>
#include <mixmod/Kernel/Model/Model.h>
#include <mixmod/Matrix/Matrix.h>

namespace OTMIXMOD
{

CLASSNAMEINIT (MixtureFactory)

/* Default constructor */
MixtureFactory::MixtureFactory () :
  OT::DistributionFactoryImplementation(),
  atomsNumber_ (0)
{
  setCovarianceModel("Gaussian_pk_Lk_C");
}

/* Parameters constructor */
MixtureFactory::MixtureFactory (const OT::UnsignedInteger atomsNumber,
                                const OT::String covarianceModel)
: OT::DistributionFactoryImplementation(),
  atomsNumber_ (atomsNumber)
{
  setCovarianceModel(covarianceModel);
}

/* Virtual constructor */
MixtureFactory * MixtureFactory::clone () const
{
  return new MixtureFactory(*this);
}

/* Here is the interface that all derived class must implement */
OT::Distribution MixtureFactory::build(const OT::Sample & sample) const
{
  return buildAsMixture(sample).clone();
}

OT::Distribution MixtureFactory::build(const OT::Sample & sample,
                                       OT::Indices & labels,
                                       OT::Point & BICLogLikelihood) const
{
  return buildAsMixture(sample, labels, BICLogLikelihood).clone();
}

OT::Mixture MixtureFactory::buildAsMixture(const OT::Sample & sample) const
{
  OT::Indices labels(0);
  OT::Point BICLogLikelihood(0);
  // Just throw out the labels as they come for free with the mixture
  return buildAsMixture(sample, labels, BICLogLikelihood);
}

OT::Mixture MixtureFactory::buildAsMixture(const OT::Sample & sample,
    OT::Indices & labels,
    OT::Point & BICLogLikelihood) const
{
  const OT::UnsignedInteger sampleSize(sample.getSize());
  if (sampleSize == 0) throw OT::InvalidArgumentException(HERE) << "Error: cannot build a MixMod distribution from an empty sample";

  if (atomsNumber_ == 0) throw OT::InvalidArgumentException(HERE) << "Error: cannot build a MixMod distribution with 0 atoms";
  // Map the data from OT to Mixmod
  // A sample must be presented as a double **
  const OT::UnsignedInteger dimension(sample.getDimension());
  double ** matrix(new double * [sampleSize]);
  for (OT::UnsignedInteger i = 0; i < sampleSize; ++i) matrix[i] = new double[dimension];
  // Copy the data into simple C structures as needed by MixMod
  for (OT::UnsignedInteger i = 0; i < sampleSize; ++i)
    for (OT::UnsignedInteger j = 0; j < dimension; ++j)
      matrix[i][j] = sample[i][j];

  XEM::GaussianData * gaussianData = new XEM::GaussianData(sampleSize, dimension, matrix);
  for (OT::UnsignedInteger i = 0; i < sampleSize; ++i) delete [] matrix[i];
  delete [] matrix;

  // Create a Mixmod description
  XEM::DataDescription dataDescription(gaussianData);
  vector<int64_t> nbCluster;
  nbCluster.push_back(atomsNumber_);

  // Prepare Mixmod for clustering
  XEM::ClusteringInput * clusteringInput(new XEM::ClusteringInput(nbCluster, dataDescription));
  XEM::ModelType modelType(XEM::StringToModelName(covarianceModel_));
  clusteringInput->setModelType(&modelType, 0);
  clusteringInput->finalize();

  // Do the computation
  XEM::ClusteringMain clusteringMain(clusteringInput);
  clusteringMain.run(seed_);

  // Extract the results
  XEM::ClusteringOutput * clusteringOutput(clusteringMain.getOutput());

  XEM::ClusteringModelOutput * clusteringModelOutput(clusteringOutput->getClusteringModelOutput(0));
  XEM::ParameterDescription * paramDescription(clusteringModelOutput->getParameterDescription());
  if (paramDescription == NULL) throw OT::InternalException(HERE) << "Error: Mixmod is unable to estimate a mixture with the given data and the current number of atoms. You may have repeated points in your data, a situation not well handled by Mixmod.";
  XEM::Parameter * paramTmp(paramDescription->getParameter());
  XEM::GaussianEDDAParameter *param = dynamic_cast< XEM::GaussianEDDAParameter * >(paramTmp);

  OT::Mixture::DistributionCollection coll(0);
  for (OT::UnsignedInteger i = 0; i < atomsNumber_; ++i)
  {
    OT::Point mean(dimension);
    for (OT::UnsignedInteger j = 0; j < dimension; ++j) mean[j] = param->getTabMean()[i][j];
    OT::Scalar w(param->getTabProportion()[i]);
    // A Mixmod matrix is a strange object, with no accessor to its elements...
    double ** xemMatrix(param->getTabSigma()[i]->storeToArray());
    OT::CovarianceMatrix covariance(dimension);
    for (OT::UnsignedInteger rowIndex = 0; rowIndex < dimension; ++rowIndex)
    {
      for (OT::UnsignedInteger columnIndex = 0; columnIndex <= rowIndex; ++columnIndex)
        covariance(rowIndex, columnIndex) = xemMatrix[rowIndex][columnIndex];
      delete [] xemMatrix[rowIndex];
    }
    delete [] xemMatrix;
    // Build the current atom
    OT::Normal atom(mean, covariance);
    atom.setWeight(w);
    coll.add(atom);
  }
  XEM::LabelDescription * labelDescription(clusteringModelOutput->getLabelDescription());
  labels = OT::Indices(sampleSize);
  // Labels run from 1 to nbAtoms, we want indices in {0,\dots,nbAtoms-1}
  // getTabLabel() returns a copy of original vector, it must be destroyed explicitly
  int64_t * tabLabels = labelDescription->getLabel()->getTabLabel();
  for (OT::UnsignedInteger i = 0; i < sampleSize; ++i) labels[i] = tabLabels[i] - 1;
  delete [] tabLabels;

  BICLogLikelihood.resize(3);
  BICLogLikelihood[0] = clusteringModelOutput->getLikelihood();
  BICLogLikelihood[1] = clusteringModelOutput->getCompletedLikelihood();
  BICLogLikelihood[2] = clusteringModelOutput->getEntropy();
  return OT::Mixture(coll);
}

OT::Distribution MixtureFactory::build() const
{
  return OT::Mixture(OT::Mixture::DistributionCollection(1, OT::Normal())).clone();
}

/* Atoms number accessors */
void MixtureFactory::setAtomsNumber (const OT::UnsignedInteger & atomsNumber)
{
  atomsNumber_ = atomsNumber;
}

OT::UnsignedInteger MixtureFactory::getAtomsNumber () const
{
  return atomsNumber_;
}

/* MixmodCovariance model accessors */
void MixtureFactory::setCovarianceModel (const OT::String covarianceModel)
{
  (void) XEM::StringToModelName(covarianceModel);
  covarianceModel_ = covarianceModel;
}

OT::String MixtureFactory::getCovarianceModel () const
{
  return covarianceModel_;
}

/* Partition a given sample into nbClusters according to the given labels */
MixtureFactory::SampleCollection MixtureFactory::BuildClusters(const OT::Sample & data,
    const OT::Indices & labels,
    const OT::UnsignedInteger nbClusters)
{
  const OT::UnsignedInteger size(data.getSize());
  if (labels.getSize() != size) throw OT::InvalidArgumentException(HERE) << "Error: the data size=" << size << " must be equal to the labels size=" << labels.getSize();
  SampleCollection clusters(nbClusters, OT::Sample(0, data.getDimension()));
  for (OT::UnsignedInteger i = 0; i < size; ++i)
  {
    const OT::UnsignedInteger currentLabel(labels[i]);
    if (currentLabel >= nbClusters) throw OT::InvalidArgumentException(HERE) << "Error: the label=" << currentLabel << " at position=" << i << " is greater or equal to the number of clusters=" << nbClusters;
    clusters[currentLabel].add(data[i]);
  }
  return clusters;
}

/* Mixmod PRNG state accessor */
void MixtureFactory::setSeed(const OT::SignedInteger seed)
{
  seed_ = seed;
}

} // namespace OTMIXMOD
