// SWIG file MixtureClassifierFactory.i

%{
#include "otmixmod/MixtureClassifierFactory.hxx"
%}

%include otmixmod/MixtureClassifierFactory.hxx
namespace OTMIXMOD { %extend MixtureClassifierFactory { MixtureClassifierFactory(const MixtureClassifierFactory & other) { return new OTMIXMOD::MixtureClassifierFactory(other); } }}

