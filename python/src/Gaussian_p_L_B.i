// SWIG file Gaussian_p_L_B.i

%{
#include "otmixmod/Gaussian_p_L_B.hxx"
%}



%include otmixmod/Gaussian_p_L_B.hxx
namespace OTMIXMOD { %extend Gaussian_p_L_B { Gaussian_p_L_B(const Gaussian_p_L_B & other) { return new OTMIXMOD::Gaussian_p_L_B(other); } }}
