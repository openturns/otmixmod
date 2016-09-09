/**
 * @file  MixtureFactory.hxx
 * @brief Top-level class for mixture factory using MixMod.
 *
 *
 *  (C) Copyright 2005-2011 EADS
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
#ifndef OTMIXMOD_MIXTUREFACTORY_HXX
#define OTMIXMOD_MIXTUREFACTORY_HXX

#include "MixmodCovarianceModel.hxx"
#include "MixmodCovarianceModelImplementation.hxx"
#include "Gaussian_pk_Lk_C.hxx"

#include <openturns/OTprivate.hxx>
#include <openturns/DistributionFactoryImplementation.hxx>
#include <openturns/Mixture.hxx>
#include <openturns/Indices.hxx>


namespace OTMIXMOD
{

  /**
   * @class MixtureFactory
   */
  class MixtureFactory
    : public OT::DistributionFactoryImplementation
  {
    CLASSNAME;
  public:

    typedef OT::Collection< OT::NumericalSample > NumericalSampleCollection;

    /** Default constructor */
    MixtureFactory();

    /** Parameters constructor */
    MixtureFactory(const OT::UnsignedInteger atomsNumber,
                   const MixmodCovarianceModelImplementation & covarianceModel = Gaussian_pk_Lk_C());
    MixtureFactory(const OT::UnsignedInteger atomsNumber,
                   const MixmodCovarianceModel & covarianceModel);

    /** Virtual constructor */
    virtual MixtureFactory * clone() const;

    /** Here is the interface that all derived class must implement */
    using OT::DistributionFactoryImplementation::build;
    Implementation build(const OT::NumericalSample & sample) const;
    Implementation build(const OT::NumericalSample & sample,
                         OT::Indices & labels,
                         OT::NumericalPoint & BICLogLikelihood) const;
    Implementation build(const OT::DistributionFactoryImplementation::NumericalPointCollection & parameters) const;
    Implementation build() const;
    OT::Mixture buildAsMixture(const OT::NumericalSample & sample) const;
    OT::Mixture buildAsMixture(const OT::NumericalSample & sample,
                               OT::Indices & labels,
                               OT::NumericalPoint & BICLogLikelihood) const;

    /** Mixture Factory accessors */
    /** AtomsNumber accessors */
    void setAtomsNumber(const OT::UnsignedInteger & number);
    OT::UnsignedInteger getAtomsNumber() const;

    /** MixmodCovariance model accessors */
    void setCovarianceModel(const MixmodCovarianceModel & covarianceModel);
    MixmodCovarianceModel getCovarianceModel() const;

    /** Partition a given sample into nbClusters according to the given labels */
    static NumericalSampleCollection BuildClusters(const OT::NumericalSample & data,
                                                   const OT::Indices & labels,
                                                   const OT::UnsignedInteger nbClusters);

    /** Mixmod PRNG state accessor */
    void setState(const OT::UnsignedInteger yState,
                  const OT::UnsignedInteger zState);

  private:
    /** The main parameter set of the factory */
    OT::UnsignedInteger atomsNumber_;
    MixmodCovarianceModel covarianceModel_;

    /** \todo Later :
     * MixModAlgorithm mixmodAlgorithm_;
     */

  }; /* class MixtureFactory */


} // namespace OTMIXMOD

#endif /* OTMIXMOD_MIXTUREFACTORY_HXX */

