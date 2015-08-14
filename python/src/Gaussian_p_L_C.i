// SWIG file Gaussian_p_L_C.i

%{
#include "Gaussian_p_L_C.hxx"
%}



%include Gaussian_p_L_C.hxx
namespace OTMIXMOD { %extend Gaussian_p_L_C { Gaussian_p_L_C(const Gaussian_p_L_C & other) { return new OTMIXMOD::Gaussian_p_L_C(other); } }}
