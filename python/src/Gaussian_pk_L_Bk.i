// SWIG file Gaussian_pk_L_Bk.i

%{
#include "otmixmod/Gaussian_pk_L_Bk.hxx"
%}



%include otmixmod/Gaussian_pk_L_Bk.hxx
namespace OTMIXMOD { %extend Gaussian_pk_L_Bk { Gaussian_pk_L_Bk(const Gaussian_pk_L_Bk & other) { return new OTMIXMOD::Gaussian_pk_L_Bk(other); } }}
