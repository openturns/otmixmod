// SWIG file MixmodCovarianceModelImplementation.i

%{
#include "otmixmod/MixmodCovarianceModelImplementation.hxx"
%}



%include otmixmod/MixmodCovarianceModelImplementation.hxx
namespace OTMIXMOD { %extend MixmodCovarianceModelImplementation { MixmodCovarianceModelImplementation(const MixmodCovarianceModelImplementation & other) { return new OTMIXMOD::MixmodCovarianceModelImplementation(other); } }}
