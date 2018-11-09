// SWIG file Gaussian_p_L_Dk_A_Dk.i

%{
#include "otmixmod/Gaussian_p_L_Dk_A_Dk.hxx"
%}



%include otmixmod/Gaussian_p_L_Dk_A_Dk.hxx
namespace OTMIXMOD { %extend Gaussian_p_L_Dk_A_Dk { Gaussian_p_L_Dk_A_Dk(const Gaussian_p_L_Dk_A_Dk & other) { return new OTMIXMOD::Gaussian_p_L_Dk_A_Dk(other); } }}
