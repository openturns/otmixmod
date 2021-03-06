/***************************************************************************
                             SRC/MIXMOD/XEMEMAlgo.h  description
    copyright            : (C) MIXMOD Team - 2001-2011
    email                : contact@mixmod.org
***************************************************************************/

/***************************************************************************
    This file is part of MIXMOD

    MIXMOD is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MIXMOD is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MIXMOD.  If not, see <http://www.gnu.org/licenses/>.

    All informations available on : http://www.mixmod.org
***************************************************************************/
#ifndef XEMEMALGO_H
#define XEMEMALGO_H

#include "XEMAlgo.h"

/**
   @brief Derived class of XEMAlgo for EM Algorithm(s)
   @author F Langrognet & A Echenim
*/

class XEMEMAlgo : public XEMAlgo{

 public:

  /// Default constructor
  XEMEMAlgo();

  /// Copy constructor
  XEMEMAlgo(const XEMEMAlgo & emAlgo);

  /// Constructor
  XEMEMAlgo(XEMAlgoStopName algoStopName, double epsilon, int64_t nbIteration);

  /// Destructor
  ~XEMEMAlgo();

  /// clone
  XEMAlgo * clone();

  /// Run method
  virtual void run(XEMModel *& model);

  const XEMAlgoName getAlgoName() const;
};

inline const XEMAlgoName XEMEMAlgo::getAlgoName() const{
  return EM;
}

#endif
