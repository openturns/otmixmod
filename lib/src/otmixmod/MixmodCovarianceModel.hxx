//                                               -*- C++ -*-
/**
 *  @brief Abstract top-level class for all the covariance models
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
#ifndef OTMIXMOD_COVARIANCEMODEL_HXX
#define OTMIXMOD_COVARIANCEMODEL_HXX

#include <openturns/TypedInterfaceObject.hxx>

#include "MixmodCovarianceModelImplementation.hxx"

namespace OTMIXMOD
{

/**
 * @class MixmodCovarianceModel
 *
 * @brief The class describes the concept of a covariance model.
 *
 * The implementation defined what covariance model is actually assumed for
 * the several atoms of a mixture.
 * @see MixmodCovarianceModelImplementation
 */
class MixmodCovarianceModel
  : public OT::TypedInterfaceObject<MixmodCovarianceModelImplementation>
{
  CLASSNAME
public:

  /** Default constructor */
  MixmodCovarianceModel();

  /** Constructor from implementation */
  MixmodCovarianceModel(const MixmodCovarianceModelImplementation & impl);

  /** MixMod name accessor */
  OT::String convertToMixmod() const;

}; /* class MixmodCovarianceModel */

} // namespace OTMIXMOD

#endif /* OTMIXMOD_COVARIANCEMODEL_HXX */
