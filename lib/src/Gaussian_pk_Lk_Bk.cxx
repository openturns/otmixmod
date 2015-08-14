//                                               -*- C++ -*-
/**
 *  @file  Gaussian_pk_Lk_Bk.cxx
 *  @brief Implementation of the gaussian_pk_Lk_Bk covariance model
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
#include "Gaussian_pk_Lk_Bk.hxx"
#include "PersistentObjectFactory.hxx"

namespace OTMIXMOD
{

  CLASSNAMEINIT(Gaussian_pk_Lk_Bk);

  /* Default constructor */
  Gaussian_pk_Lk_Bk::Gaussian_pk_Lk_Bk()
    : MixmodCovarianceModelImplementation()
  {
    // Nothing to do
  }

  /* Here is the interface that all derived class must implement */

  /* Virtual constructor */
  Gaussian_pk_Lk_Bk * Gaussian_pk_Lk_Bk::clone() const
  {
    return new Gaussian_pk_Lk_Bk(*this);
  }

  /* Mixmod name accessor */
  OT::String Gaussian_pk_Lk_Bk::convertToMixmod() const
  {
    return "Gaussian_pk_Lk_Bk";
  }

} // namespace OTMIXMOD
