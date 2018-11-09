// SWIG file Gaussian_pk_L_B.i

%{
#include "otmixmod/Gaussian_pk_L_B.hxx"
%}



%include otmixmod/Gaussian_pk_L_B.hxx
namespace OTMIXMOD { %extend Gaussian_pk_L_B { Gaussian_pk_L_B(const Gaussian_pk_L_B & other) { return new OTMIXMOD::Gaussian_pk_L_B(other); } }}
