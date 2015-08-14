// SWIG file MixmodCovarianceModel.i

%{
#include "MixmodCovarianceModel.hxx"
%}

%template(MixmodCovarianceModelImplementationFactoryTypedInterfaceObject) OT::TypedInterfaceObject<OTMIXMOD::MixmodCovarianceModelImplementation>;

%include MixmodCovarianceModel.hxx
namespace OTMIXMOD { %extend MixmodCovarianceModel { MixmodCovarianceModel(const MixmodCovarianceModel & other) { return new OTMIXMOD::MixmodCovarianceModel(other); } }}
