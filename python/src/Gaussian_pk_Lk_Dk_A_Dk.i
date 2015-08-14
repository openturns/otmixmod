// SWIG file Gaussian_pk_Lk_Dk_A_Dk.i

%{
#include "Gaussian_pk_Lk_Dk_A_Dk.hxx"
%}



%include Gaussian_pk_Lk_Dk_A_Dk.hxx
namespace OTMIXMOD { %extend Gaussian_pk_Lk_Dk_A_Dk { Gaussian_pk_Lk_Dk_A_Dk(const Gaussian_pk_Lk_Dk_A_Dk & other) { return new OTMIXMOD::Gaussian_pk_Lk_Dk_A_Dk(other); } }}
