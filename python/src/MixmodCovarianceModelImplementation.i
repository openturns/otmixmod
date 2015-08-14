// SWIG file MixmodCovarianceModelImplementation.i

%{
#include "MixmodCovarianceModelImplementation.hxx"
%}



%include MixmodCovarianceModelImplementation.hxx
namespace OTMIXMOD { %extend MixmodCovarianceModelImplementation { MixmodCovarianceModelImplementation(const MixmodCovarianceModelImplementation & other) { return new OTMIXMOD::MixmodCovarianceModelImplementation(other); } }}
