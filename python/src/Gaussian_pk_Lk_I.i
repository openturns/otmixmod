// SWIG file Gaussian_pk_Lk_I.i

%{
#include "otmixmod/Gaussian_pk_Lk_I.hxx"
%}



%include otmixmod/Gaussian_pk_Lk_I.hxx
namespace OTMIXMOD { %extend Gaussian_pk_Lk_I { Gaussian_pk_Lk_I(const Gaussian_pk_Lk_I & other) { return new OTMIXMOD::Gaussian_pk_Lk_I(other); } }}
