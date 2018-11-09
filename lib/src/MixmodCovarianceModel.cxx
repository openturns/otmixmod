//                                               -*- C++ -*-
/**
 *  @brief Abstract top-level class for all MixmodCovarianceModel
 *
 *  (C) Copyright 2011-2011 EADS
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
#include "otmixmod/MixmodCovarianceModel.hxx"
#include "otmixmod/Gaussian_pk_Lk_C.hxx"

namespace OTMIXMOD
{

CLASSNAMEINIT(MixmodCovarianceModel)

/* Default constructor */
MixmodCovarianceModel::MixmodCovarianceModel()
  : OT::TypedInterfaceObject<MixmodCovarianceModelImplementation>(new Gaussian_pk_Lk_C)
{
  // Nothing to do
}


/* Constructor from implementation */
MixmodCovarianceModel::MixmodCovarianceModel(const MixmodCovarianceModelImplementation & impl)
  : OT::TypedInterfaceObject<MixmodCovarianceModelImplementation>(impl.clone())
{
  // Nothing to do
}


/* MixMod name accessor */
OT::String MixmodCovarianceModel::convertToMixmod() const
{
  return getImplementation()->convertToMixmod();
}

} // namespace OTMIXMOD
