// SWIG file MixtureClassifierFactory.i

%{
#include "MixtureClassifierFactory.hxx"
%}

%include MixtureClassifierFactory.hxx
namespace OTMIXMOD { %extend MixtureClassifierFactory { MixtureClassifierFactory(const MixtureClassifierFactory & other) { return new OTMIXMOD::MixtureClassifierFactory(other); } }}

