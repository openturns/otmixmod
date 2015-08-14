// SWIG file MixtureFactory.i

// do not pass argument by reference, return it as tuple item
%typemap(in, numinputs=0) (OT::Indices & labels, OT::NumericalPoint & BICLogLikelihood) ($*1_ltype temp1,$*2_ltype temp2) %{ temp1 = OT::Indices(); $1 = &temp1; temp2=OT::NumericalPoint(); $2=&temp2; %} 
%typemap(argout) (OT::Indices & labels, OT::NumericalPoint & BICLogLikelihood) %{ $result = SWIG_Python_AppendOutput($result, SWIG_NewPointerObj(new OT::Indices(*$1), SWIG_TypeQuery("OT::Indices *"), SWIG_POINTER_OWN |  0 ));
$result= SWIG_Python_AppendOutput($result, SWIG_NewPointerObj(new OT::NumericalPoint(*$2), SWIG_TypeQuery("OT::NumericalPoint *"), SWIG_POINTER_OWN |  0 )); %} 
OT::Mixture OTMIXMOD::MixtureFactory::buildAsMixture(const OT::NumericalSample & sample, OT::Indices & labels, OT::NumericalPoint & BICLogLikelihood) const;
OT::Implementation OTMIXMOD::MixtureFactory::build(const OT::NumericalSample & sample, OT::Indices & labels, OT::NumericalPoint & BICLogLikelihood) const;
%ignore OTMIXMOD::MixtureFactory::buildAsMixture(const OT::NumericalSample & sample) const;
%ignore OTMIXMOD::MixtureFactory::build(const OT::NumericalSample & sample) const;

%{
#include "MixtureFactory.hxx"
%}

%template(NumericalSampleCollection)           OT::Collection<OT::NumericalSample>;

%include MixtureFactory.hxx
namespace OTMIXMOD { %extend MixtureFactory { MixtureFactory(const MixtureFactory & other) { return new OTMIXMOD::MixtureFactory(other); } }}

