//                                               -*- C++ -*-
/**
 *  @file  Gaussian_pk_Lk_B.cxx
 *  @brief Implementation of the gaussian_pk_Lk_B covariance model
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
#include "Gaussian_pk_Lk_B.hxx"

#include <openturns/PersistentObjectFactory.hxx>

namespace OTMIXMOD
{

  CLASSNAMEINIT(Gaussian_pk_Lk_B)

  /* Default constructor */
  Gaussian_pk_Lk_B::Gaussian_pk_Lk_B()
    : MixmodCovarianceModelImplementation()
  {
    // Nothing to do
  }

  /* Here is the interface that all derived class must implement */

  /* Virtual constructor */
  Gaussian_pk_Lk_B * Gaussian_pk_Lk_B::clone() const
  {
    return new Gaussian_pk_Lk_B(*this);
  }

  /* Mixmod name accessor */
  OT::String Gaussian_pk_Lk_B::convertToMixmod() const
  {
    return "Gaussian_pk_Lk_B";
  }

} // namespace OTMIXMOD
