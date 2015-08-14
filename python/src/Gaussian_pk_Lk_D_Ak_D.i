// SWIG file Gaussian_pk_Lk_D_Ak_D.i

%{
#include "Gaussian_pk_Lk_D_Ak_D.hxx"
%}



%include Gaussian_pk_Lk_D_Ak_D.hxx
namespace OTMIXMOD { %extend Gaussian_pk_Lk_D_Ak_D { Gaussian_pk_Lk_D_Ak_D(const Gaussian_pk_Lk_D_Ak_D & other) { return new OTMIXMOD::Gaussian_pk_Lk_D_Ak_D(other); } }}
