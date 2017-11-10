//                                               -*- C++ -*-
/**
 *  @file  Gaussian_p_L_Bk.hxx
 *  @brief Implementation of the gaussian_p_L_Bk covariance model
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
#ifndef OTMIXMOD_GAUSSIAN_P_L_BK_HXX
#define OTMIXMOD_GAUSSIAN_P_L_BK_HXX

#include "MixmodCovarianceModelImplementation.hxx"

namespace OTMIXMOD
{

  /**
   * @class Gaussian_p_L_Bk
   *
   * @brief The class implements the gaussian_p_L_Bk covariance model
   *
   * This class is derived from MixmodCovarianceModelImplementation.
   */
  class Gaussian_p_L_Bk
    : public MixmodCovarianceModelImplementation
  {
    CLASSNAME
  public:

    /** Default constructor */
    explicit Gaussian_p_L_Bk();

    /* Here is the interface that all derived class must implement */

    /* Virtual constructor */
    virtual Gaussian_p_L_Bk * clone() const;

    /** MixMod name accessor */
    virtual OT::String convertToMixmod() const;

  }; /* class Gaussian_p_L_Bk */

} // namespace OTMIXMOD

#endif /* OTMIXMOD_GAUSSIAN_P_L_BK_HXX */
