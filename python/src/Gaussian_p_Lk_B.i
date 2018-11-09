// SWIG file Gaussian_p_Lk_B.i

%{
#include "otmixmod/Gaussian_p_Lk_B.hxx"
%}



%include otmixmod/Gaussian_p_Lk_B.hxx
namespace OTMIXMOD { %extend Gaussian_p_Lk_B { Gaussian_p_Lk_B(const Gaussian_p_Lk_B & other) { return new OTMIXMOD::Gaussian_p_Lk_B(other); } }}
