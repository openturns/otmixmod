// SWIG file Gaussian_pk_L_I.i

%{
#include "otmixmod/Gaussian_pk_L_I.hxx"
%}



%include otmixmod/Gaussian_pk_L_I.hxx
namespace OTMIXMOD { %extend Gaussian_pk_L_I { Gaussian_pk_L_I(const Gaussian_pk_L_I & other) { return new OTMIXMOD::Gaussian_pk_L_I(other); } }}
