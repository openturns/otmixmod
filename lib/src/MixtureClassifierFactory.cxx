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

#include "otmixmod/MixtureClassifierFactory.hxx"

namespace OTMIXMOD
{

CLASSNAMEINIT (MixtureClassifierFactory)

/* Default constructor */
MixtureClassifierFactory::MixtureClassifierFactory ()
  : OT::Object()
  , mixtureFactory_()
{
  // Nothing to do
}

/* Parameters constructor */
MixtureClassifierFactory::MixtureClassifierFactory (const MixtureFactory & mixtureFactory)
  : OT::Object()
  , mixtureFactory_(mixtureFactory)
{
  // Nothing to do
}

/* Virtual constructor */
MixtureClassifierFactory * MixtureClassifierFactory::clone () const
{
  return new MixtureClassifierFactory(*this);
}

/* Build a classifier from a sample using the mixture factory */
OT::MixtureClassifier MixtureClassifierFactory::build(const OT::Sample & sample) const
{
  return OT::MixtureClassifier(mixtureFactory_.buildAsMixture(sample));
}


/* MixtureClassifier accessors */
MixtureFactory MixtureClassifierFactory::getMixtureFactory() const
{
  return mixtureFactory_;
}

void MixtureClassifierFactory::setMixtureFactory(const MixtureFactory & mixtureFactory)
{
  mixtureFactory_ = mixtureFactory;
}

} // namespace OTMIXMOD
