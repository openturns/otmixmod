// SWIG file Gaussian_p_Lk_Dk_A_Dk.i

%{
#include "Gaussian_p_Lk_Dk_A_Dk.hxx"
%}



%include Gaussian_p_Lk_Dk_A_Dk.hxx
namespace OTMIXMOD { %extend Gaussian_p_Lk_Dk_A_Dk { Gaussian_p_Lk_Dk_A_Dk(const Gaussian_p_Lk_Dk_A_Dk & other) { return new OTMIXMOD::Gaussian_p_Lk_Dk_A_Dk(other); } }}

