// SWIG file
// Author : schueller
// Date : 2008-08-28 17:36:47 +0200 (Thu, 28 Aug 2008)

%module(docstring="otmixmod module") otmixmod
%feature("autodoc","1");

%{
#include "OT.hxx"
#include "PythonWrappingFunctions.hxx" 
%}

// Prerequisites needed
%include typemaps.i
%include exception.i

%import base_module.i
%import uncertainty_module.i

// The new classes
%include MixmodCovarianceModelImplementation.i
%include Gaussian_pk_L_B.i
%include Gaussian_pk_L_Bk.i
%include Gaussian_pk_L_C.i
%include Gaussian_pk_L_Ck.i
%include Gaussian_pk_L_D_Ak_D.i
%include Gaussian_pk_L_Dk_A_Dk.i
%include Gaussian_pk_L_I.i
%include Gaussian_pk_Lk_B.i
%include Gaussian_pk_Lk_Bk.i
%include Gaussian_pk_Lk_C.i
%include Gaussian_pk_Lk_Ck.i
%include Gaussian_pk_Lk_D_Ak_D.i
%include Gaussian_pk_Lk_Dk_A_Dk.i
%include Gaussian_pk_Lk_I.i
%include Gaussian_p_L_B.i
%include Gaussian_p_L_Bk.i
%include Gaussian_p_L_C.i
%include Gaussian_p_L_Ck.i
%include Gaussian_p_L_D_Ak_D.i
%include Gaussian_p_L_Dk_A_Dk.i
%include Gaussian_p_L_I.i
%include Gaussian_p_Lk_B.i
%include Gaussian_p_Lk_Bk.i
%include Gaussian_p_Lk_C.i
%include Gaussian_p_Lk_Ck.i
%include Gaussian_p_Lk_D_Ak_D.i
%include Gaussian_p_Lk_Dk_A_Dk.i
%include Gaussian_p_Lk_I.i
%include MixmodCovarianceModel.i
%include MixtureFactory.i
%include MixtureClassifierFactory.i
