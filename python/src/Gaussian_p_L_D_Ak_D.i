// SWIG file Gaussian_p_L_D_Ak_D.i

%{
#include "Gaussian_p_L_D_Ak_D.hxx"
%}



%include Gaussian_p_L_D_Ak_D.hxx
namespace OTMIXMOD { %extend Gaussian_p_L_D_Ak_D { Gaussian_p_L_D_Ak_D(const Gaussian_p_L_D_Ak_D & other) { return new OTMIXMOD::Gaussian_p_L_D_Ak_D(other); } }}
