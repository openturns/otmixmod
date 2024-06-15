/**
 * @brief Top-level class for mixture factory using MixMod.
 *
 *
 *  Copyright 2005-2024 Airbus-EDF-IMACS-Phimeca
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
  CLASSNAME
public:

  typedef OT::Collection< OT::Sample > SampleCollection;

  static OT::Description GetValidCovarianceModels();

  /** Default constructor */
  MixtureFactory();

  /** Parameters constructor */
  explicit MixtureFactory(const OT::UnsignedInteger atomsNumber,
                          const OT::String covarianceModel = "Gaussian_pk_Lk_C");

  /** Virtual constructor */
  MixtureFactory * clone() const override;

  /** Here is the interface that all derived class must implement */
  using OT::DistributionFactoryImplementation::build;
  OT::Distribution build(const OT::Sample & sample) const override;
  OT::Distribution build(const OT::Sample & sample,
                         OT::Indices & labels,
                         OT::Point & BICLogLikelihood) const;
  OT::Distribution build() const override;
  OT::Mixture buildAsMixture(const OT::Sample & sample) const;
  OT::Mixture buildAsMixture(const OT::Sample & sample,
                             OT::Indices & labels,
                             OT::Point & BICLogLikelihood) const;

  /** Mixture Factory accessors */
  /** AtomsNumber accessors */
  void setAtomsNumber(const OT::UnsignedInteger & number);
  OT::UnsignedInteger getAtomsNumber() const;

  /** MixmodCovariance model accessors */
  void setCovarianceModel(const OT::String covarianceModel);
  OT::String getCovarianceModel() const;

  /** Partition a given sample into nbClusters according to the given labels */
  static SampleCollection BuildClusters(const OT::Sample & data,
                                        const OT::Indices & labels,
                                        const OT::UnsignedInteger nbClusters);

  /** Mixmod PRNG state accessor */
  void setSeed(const OT::SignedInteger seed);

private:
  /** The main parameter set of the factory */
  OT::UnsignedInteger atomsNumber_ = 0;
  OT::String covarianceModel_;

  OT::SignedInteger seed_ = 0;

  /** \todo Later :
   * MixModAlgorithm mixmodAlgorithm_;
   */

}; /* class MixtureFactory */


} // namespace OTMIXMOD

#endif /* OTMIXMOD_MIXTUREFACTORY_HXX */

