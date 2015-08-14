// SWIG file Gaussian_pk_L_C.i

%{
#include "Gaussian_pk_L_C.hxx"
%}



%include Gaussian_pk_L_C.hxx
namespace OTMIXMOD { %extend Gaussian_pk_L_C { Gaussian_pk_L_C(const Gaussian_pk_L_C & other) { return new OTMIXMOD::Gaussian_pk_L_C(other); } }}
