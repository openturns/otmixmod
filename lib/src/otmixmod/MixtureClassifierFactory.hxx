/**
 * @brief Top-level class for mixture factory using MixMod.
 *
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
#ifndef OTMIXMOD_MIXTURECLASSIFIERFACTORY_HXX
#define OTMIXMOD_MIXTURECLASSIFIERFACTORY_HXX

#include <openturns/OTprivate.hxx>
#include <openturns/MixtureClassifier.hxx>

#include "MixtureFactory.hxx"

namespace OTMIXMOD
{

/**
 * @class MixtureClassifierFactory
 */
class MixtureClassifierFactory : public OT::Object
{
  CLASSNAME
public:

  /** Default constructor */
  MixtureClassifierFactory();

  /** Parameters constructor */
  MixtureClassifierFactory(const MixtureFactory & mixtureFactory);

  /** Virtual constructor */
  virtual MixtureClassifierFactory * clone() const;

  /** Build a classifier from a sample using the mixture factory */
  OT::MixtureClassifier build(const OT::Sample & sample) const;

  /** Mixture Factory accessors */
  MixtureFactory getMixtureFactory() const;
  void setMixtureFactory(const MixtureFactory & mixtureFactory);

private:

  /** The underlying mixture factory */
  MixtureFactory mixtureFactory_;

}; /* class MixtureClassifierFactory */


} // namespace OTMIXMOD

#endif /* OTMIXMOD_MIXTURECLASSIFIERFACTORY_HXX */

