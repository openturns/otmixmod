// SWIG file
// Author : schueller
// Date : 2008-08-28 17:36:47 +0200 (Thu, 28 Aug 2008)

%module(docstring="otmixmod module") otmixmod
%feature("autodoc","1");

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
