// SWIG file Gaussian_pk_L_Ck.i

%{
#include "otmixmod/Gaussian_pk_L_Ck.hxx"
%}



%include otmixmod/Gaussian_pk_L_Ck.hxx
namespace OTMIXMOD { %extend Gaussian_pk_L_Ck { Gaussian_pk_L_Ck(const Gaussian_pk_L_Ck & other) { return new OTMIXMOD::Gaussian_pk_L_Ck(other); } }}
