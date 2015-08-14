// SWIG file Gaussian_p_Lk_C.i

%{
#include "Gaussian_p_Lk_C.hxx"
%}



%include Gaussian_p_Lk_C.hxx
namespace OTMIXMOD { %extend Gaussian_p_Lk_C { Gaussian_p_Lk_C(const Gaussian_p_Lk_C & other) { return new OTMIXMOD::Gaussian_p_Lk_C(other); } }}
