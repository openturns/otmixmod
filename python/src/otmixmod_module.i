%module(docstring="otmixmod module") otmixmod

%{
#include "openturns/OT.hxx"
#include "openturns/PythonWrappingFunctions.hxx" 
%}

// Prerequisites needed
%include typemaps.i
%include exception.i

%import base_module.i
%import uncertainty_module.i

// The new classes
%include MixtureFactory.i
