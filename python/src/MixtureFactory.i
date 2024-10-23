// SWIG file MixtureFactory.i

// do not pass argument by reference, return it as tuple item
%typemap(in, numinputs=0) (OT::Indices & labels, OT::Point & BICLogLikelihood) ($*1_ltype temp1,$*2_ltype temp2) %{ temp1 = OT::Indices(); $1 = &temp1; temp2=OT::Point(); $2=&temp2; %} 
%typemap(argout) (OT::Indices & labels, OT::Point & BICLogLikelihood) %{ $result = OT::AppendOutput($result, SWIG_NewPointerObj(new OT::Indices(*$1), SWIG_TypeQuery("OT::Indices *"), SWIG_POINTER_OWN));
$result = OT::AppendOutput($result, SWIG_NewPointerObj(new OT::Point(*$2), SWIG_TypeQuery("OT::Point *"), SWIG_POINTER_OWN)); %} 
OT::Mixture OTMIXMOD::MixtureFactory::buildAsMixture(const OT::Sample & sample, OT::Indices & labels, OT::Point & BICLogLikelihood) const;
OT::Implementation OTMIXMOD::MixtureFactory::build(const OT::Sample & sample, OT::Indices & labels, OT::Point & BICLogLikelihood) const;
%ignore OTMIXMOD::MixtureFactory::buildAsMixture(const OT::Sample & sample) const;
%ignore OTMIXMOD::MixtureFactory::build(const OT::Sample & sample) const;

%{
#include "otmixmod/MixtureFactory.hxx"
%}

%include MixtureFactory_doc.i 

%copyctor OTMIXMOD::MixtureFactory;

%include otmixmod/MixtureFactory.hxx

