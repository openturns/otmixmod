// SWIG file Gaussian_pk_Lk_B.i

%{
#include "otmixmod/Gaussian_pk_Lk_B.hxx"
%}



%include otmixmod/Gaussian_pk_Lk_B.hxx
namespace OTMIXMOD { %extend Gaussian_pk_Lk_B { Gaussian_pk_Lk_B(const Gaussian_pk_Lk_B & other) { return new OTMIXMOD::Gaussian_pk_Lk_B(other); } }}
