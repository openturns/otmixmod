// SWIG file Gaussian_p_Lk_Ck.i

%{
#include "Gaussian_p_Lk_Ck.hxx"
%}

%include Gaussian_p_Lk_Ck.hxx
namespace OTMIXMOD { %extend Gaussian_p_Lk_Ck { Gaussian_p_Lk_Ck(const Gaussian_p_Lk_Ck & other) { return new OTMIXMOD::Gaussian_p_Lk_Ck(other); } }}
