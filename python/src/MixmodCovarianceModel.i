// SWIG file MixmodCovarianceModel.i

%{
#include "otmixmod/MixmodCovarianceModel.hxx"
%}

%template(MixmodCovarianceModelImplementationFactoryTypedInterfaceObject) OT::TypedInterfaceObject<OTMIXMOD::MixmodCovarianceModelImplementation>;

%include otmixmod/MixmodCovarianceModel.hxx
namespace OTMIXMOD { %extend MixmodCovarianceModel { MixmodCovarianceModel(const MixmodCovarianceModel & other) { return new OTMIXMOD::MixmodCovarianceModel(other); } }}
