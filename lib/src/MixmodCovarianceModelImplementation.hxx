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
#ifndef OTMIXMOD_COVARIANCEMODELIMPLEMENTATION_HXX
#define OTMIXMOD_COVARIANCEMODELIMPLEMENTATION_HXX

#include <openturns/OTprivate.hxx>
#include <openturns/PersistentObject.hxx>

namespace OTMIXMOD
{

  /**
   * @class MixmodCovarianceModelImplementation
   *
   * @brief The class implements the concept of comparison operator defined in MixmodCovarianceModel.
   *
   * This class is abstract so it can not be instanciated. It must be derived.
   * @see MixmodCovarianceModel
   */
  class MixmodCovarianceModelImplementation
    : public OT::PersistentObject
  {
    CLASSNAME
  public:

    /** Default constructor */
    MixmodCovarianceModelImplementation();

    /** MixMod name accessor */
    virtual OT::String convertToMixmod() const;

    /* Virtual constructor */
    virtual MixmodCovarianceModelImplementation * clone() const = 0;

  }; /* class MixmodCovarianceModelImplementation */

} // namespace OTMIXMOD

#endif /* OTMIXMOD_COVARIANCEMODELIMPLEMENTATION_HXX */
