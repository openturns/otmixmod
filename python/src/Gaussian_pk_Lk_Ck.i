// SWIG file Gaussian_pk_Lk_Ck.i

%{
#include "Gaussian_pk_Lk_Ck.hxx"
%}



%include Gaussian_pk_Lk_Ck.hxx
namespace OTMIXMOD { %extend Gaussian_pk_Lk_Ck { Gaussian_pk_Lk_Ck(const Gaussian_pk_Lk_Ck & other) { return new OTMIXMOD::Gaussian_pk_Lk_Ck(other); } }}
