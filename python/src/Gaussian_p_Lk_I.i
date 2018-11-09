// SWIG file Gaussian_p_Lk_I.i

%{
#include "otmixmod/Gaussian_p_Lk_I.hxx"
%}



%include otmixmod/Gaussian_p_Lk_I.hxx
namespace OTMIXMOD { %extend Gaussian_p_Lk_I { Gaussian_p_Lk_I(const Gaussian_p_Lk_I & other) { return new OTMIXMOD::Gaussian_p_Lk_I(other); } }}

