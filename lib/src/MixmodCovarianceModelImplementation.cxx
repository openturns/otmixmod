//                                               -*- C++ -*-
/**
 *  @brief Abstract top-level class for all MixmodCovarianceModelImplementation
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
#include "MixmodCovarianceModelImplementation.hxx"

#include <openturns/Exception.hxx>

namespace OTMIXMOD
{

  CLASSNAMEINIT(MixmodCovarianceModelImplementation)

  /* Default constructor */
  MixmodCovarianceModelImplementation::MixmodCovarianceModelImplementation()
    : PersistentObject()
  {
    // Nothing to do
  }

  /* Here is the interface that all derived class must implement */

  /** MixMod name accessor */
  OT::String MixmodCovarianceModelImplementation::convertToMixmod() const
  {
    throw OT::NotYetImplementedException(HERE);
  }

} // namespace OTMIXMOD
