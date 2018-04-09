//                                               -*- C++ -*-
/**
 *  @brief Implementation of the gaussian_p_L_Bk covariance model
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
#include "Gaussian_p_L_Bk.hxx"

#include <openturns/PersistentObjectFactory.hxx>

namespace OTMIXMOD
{

CLASSNAMEINIT(Gaussian_p_L_Bk)

/* Default constructor */
Gaussian_p_L_Bk::Gaussian_p_L_Bk()
  : MixmodCovarianceModelImplementation()
{
  // Nothing to do
}

/* Here is the interface that all derived class must implement */

/* Virtual constructor */
Gaussian_p_L_Bk * Gaussian_p_L_Bk::clone() const
{
  return new Gaussian_p_L_Bk(*this);
}

/* Mixmod name accessor */
OT::String Gaussian_p_L_Bk::convertToMixmod() const
{
  return "Gaussian_p_L_Bk";
}

} // namespace OTMIXMOD
