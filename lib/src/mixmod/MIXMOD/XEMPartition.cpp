/***************************************************************************
                             SRC/MIXMOD/XEMPartition.cpp  description
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
#include "XEMPartition.h"


//------------
// Constructor
//------------
XEMPartition::XEMPartition(){
  _nbSample  = 0;
  _nbCluster = 0;
  _tabValue  = NULL;
  _deleteValues = false;
  _partitionFile._fileName = "";
  _partitionFile._format = FormatNumeric::defaultFormatNumericFile;
  _partitionFile._type = TypePartition::defaultTypePartition;
}



//------------
// Constructor
//------------
XEMPartition::XEMPartition(XEMPartition * iPartition){
  _nbSample  = iPartition->_nbSample;
  _nbCluster = iPartition->_nbCluster;
  if (iPartition->_tabValue)
    _tabValue = copyTab((iPartition->_tabValue), iPartition->_nbSample, iPartition->_nbCluster);
  else
    _tabValue = NULL;
  _partitionFile = iPartition->getPartitionFile();
  _deleteValues = true;
}


//-----------
//Constructor
//-----------
XEMPartition::XEMPartition(int64_t nbSample, int64_t nbCluster, const XEMNumericPartitionFile & partitionFile){
  _nbSample  = nbSample;
  _nbCluster = nbCluster;
  _tabValue  = NULL;
  _partitionFile = partitionFile;
  if ((_partitionFile._fileName).compare("") != 0){
    try{
      ifstream partitionFileStream((_partitionFile._fileName).c_str(), ios::in);
      if (! partitionFileStream.is_open()){
        throw wrongPartitionFileName;
      }
      partitionFileStream>>(*this);
      partitionFileStream.close();
      _deleteValues = true;
    }
    catch(XEMErrorType errorType){
      throw errorType; // knownPartiton catch this error
    }
  }
}



//-----------
//Constructor
// used in DCV context
//-----------
XEMPartition::XEMPartition(XEMPartition * originalPartition, XEMCVBlock & block){

  _nbSample  = block._nbSample;
  _nbCluster = originalPartition->_nbCluster;

  _tabValue  = new int64_t*[_nbSample];
  int64_t ** originalTabValue= originalPartition->_tabValue ;
  int64_t indexInOriginalTabValue;
  for (int64_t i=0; i<_nbSample; i++){
    // _tabValue[i] = new int64_t[_nbCluster];
    indexInOriginalTabValue = block._tabWeightedIndividual[i].val;
    _tabValue[i] = originalTabValue[indexInOriginalTabValue];
    // _tabValue[i] = copyTab(originalTabValue[indexInOriginalTabValue],_nbCluster);

  }
  // TODO _partitionFile
  _deleteValues = false ;

}



//----------
//Destructor
//----------
XEMPartition::~XEMPartition(){
  int64_t i;
  if (_tabValue){

    if(_deleteValues){
      for (i=0; i<_nbSample; i++){
        delete[] _tabValue[i];
      }
    }

    delete[] _tabValue;
  }
  _tabValue = NULL;
}



//--------------
// Set attributs
//--------------
void XEMPartition::setDimension(int64_t nbSample, int64_t nbCluster){
  _nbSample  = nbSample;
  _nbCluster = nbCluster;
}


/* return value between -1 and _nbCluster-1
   -1 : if unknown
   0.... _nbClustrer-1 else
*/
int64_t XEMPartition::getGroupNumber(int64_t idxSample){
  int64_t res = -1;
  int64_t k=0;
  while (_tabValue[idxSample][k]==0 && k<_nbCluster){
    k++;
  }
  if (k==_nbCluster){
    res = -1;
  }
  else if (_tabValue[idxSample][k]==1){
    res = k;
  }else throw internalMixmodError;
  return res;
}



//-------------------------------------------
// verify if partition is complete
//  - each line has one (and only one) '1'
//      - each cluster appears at least one time
//-------------------------------------------
bool XEMPartition::isComplete(){
  bool res = true;
  int64_t i=0;
  int64_t k;

  // each line has one (and only one '1'
  int64_t compteurDe1=0;
  while (i<_nbSample && res){
    compteurDe1 = 0;
    for (k=0; k<_nbCluster; k++){
      if (_tabValue[i][k] == 1)
        compteurDe1++;
    }
    if (compteurDe1 != 1){
      res = false;
    }
    i++;
  }

  if (res){
    // each cluster appears at least one time
    i=0;
    int64_t nbClusterThatAppearAtLastOneTime = 0;
    int64_t * tabNbOccurenceOfCluster = new int64_t[_nbCluster];
    for (k=0; k<_nbCluster; k++){
      tabNbOccurenceOfCluster[k] = 0;
      for (i=0; i<_nbSample; i++){
        tabNbOccurenceOfCluster[k] += _tabValue[i][k];
      }
      if (tabNbOccurenceOfCluster[k] > 0){
        nbClusterThatAppearAtLastOneTime ++;
      }
    }
    delete [] tabNbOccurenceOfCluster;
    if (nbClusterThatAppearAtLastOneTime != _nbCluster){
      res=false;
    }
  }
  return res;

}



// ------------
// operator ==
//-------------
bool XEMPartition::operator==(XEMPartition & otherPartition){
  bool res = true;
  if (_nbSample!=otherPartition._nbSample || _nbCluster!=otherPartition._nbCluster){
    cout<<_nbSample<<endl;
    cout<<otherPartition._nbSample<<endl;
    cout<<_nbCluster<<endl;
    cout<<otherPartition._nbCluster<<endl;
    res = false;
  }
  else{
    int64_t i=0;
    int64_t k;
    while (i<_nbSample && res){
      k=0;
      while (k<_nbCluster && res){
        if (_tabValue[i][k] != otherPartition._tabValue[i][k]){
          res = false;
        }
        k++;
      }
      i++;
    }
  }

  return res;
}



//--------------------------
// Friend method ifstream >>
//--------------------------
ifstream & operator >> (ifstream & fi, XEMPartition & partition){
  int64_t j;/*, nbRows, indice*/;
  int64_t i;
  //int64_t compt = 0;

  partition._tabValue = new int64_t*[partition._nbSample];
  partition._deleteValues = true ;
  for (i=0; i<partition._nbSample; i++){
    partition._tabValue[i] = new int64_t[partition._nbCluster];
  }

  //for (i=0; i<label._nbSample; i++){
  i=0;
  while(i<partition._nbSample && !fi.eof()){
    for (j=0; j<partition._nbCluster; j++){
      partition._tabValue[i][j] = 0;
      fi>>partition._tabValue[i][j];
      //  compt += label._tabValue[i][j];
    }
    i++;
  }
  if (i != partition._nbSample){
    for (i=0; i<partition._nbSample; ++i){
      delete partition._tabValue[i];
    }
    delete partition._tabValue;
    partition._tabValue=NULL;

    throw errorInPartitionInput;
  }

  // Debug
  //editTab<int64_t>(partition._tabValue, partition._nbSample, partition._nbCluster);
  // End Debug
  /*
    if (compt == label._nbSample)
    label._complete = true;
    else
    label._complete = false;
    if (compt > label._nbSample)
    throw errorInLabelInput;
  */
  /*
    fi>>nbRows;

    for (i=0; i<nbRows; i++){
    fi>>indice;
    for (j=0; j<label._nbCluster ; j++){
    fi>>label._tabValue[indice-1][j];
    }
    }
  */

  return fi;
}



//-------------------------
// Friend method ostream <<
//-------------------------
ostream & operator << (ostream & fo, const XEMPartition & partition){
  fo<<"\n Sample size: "<<partition._nbSample;
  fo<<"\n Number of Cluster: "<<partition._nbCluster<< endl;
  for (int64_t i=0; i<partition._nbSample; i++){
    for (int64_t k=0; k<partition._nbCluster; k++){
      cout<<partition._tabValue[i][k]<<"\t";
    }
    cout<<endl;
  }

  return fo;
}
