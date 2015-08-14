// SWIG file Gaussian_pk_Lk_Bk.i

%{
#include "Gaussian_pk_Lk_Bk.hxx"
%}



%include Gaussian_pk_Lk_Bk.hxx
namespace OTMIXMOD { %extend Gaussian_pk_Lk_Bk { Gaussian_pk_Lk_Bk(const Gaussian_pk_Lk_Bk & other) { return new OTMIXMOD::Gaussian_pk_Lk_Bk(other); } }}
