// SWIG file Gaussian_pk_Lk_C.i

%{
#include "otmixmod/Gaussian_pk_Lk_C.hxx"
%}



%include otmixmod/Gaussian_pk_Lk_C.hxx
namespace OTMIXMOD { %extend Gaussian_pk_Lk_C { Gaussian_pk_Lk_C(const Gaussian_pk_Lk_C & other) { return new OTMIXMOD::Gaussian_pk_Lk_C(other); } }}
