// SWIG file Gaussian_p_L_Bk.i

%{
#include "otmixmod/Gaussian_p_L_Bk.hxx"
%}



%include otmixmod/Gaussian_p_L_Bk.hxx
namespace OTMIXMOD { %extend Gaussian_p_L_Bk { Gaussian_p_L_Bk(const Gaussian_p_L_Bk & other) { return new OTMIXMOD::Gaussian_p_L_Bk(other); } }}
