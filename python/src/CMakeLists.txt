
include ( ${SWIG_USE_FILE} )

include_directories ( ${OPENTURNS_SWIG_INCLUDE_DIRS} )
add_definitions( ${OPENTURNS_SWIG_DEFINITIONS} )
include_directories ( ${INTERNAL_INCLUDE_DIRS} )
include_directories ( ${PYTHON_INCLUDE_DIRS} )

macro ( ot_add_python_module MODULENAME SOURCEFILE )
  set_source_files_properties ( ${SOURCEFILE} PROPERTIES CPLUSPLUS ON )
  set_source_files_properties ( ${SOURCEFILE} PROPERTIES SWIG_MODULE_NAME ${MODULENAME} )
  ot_install_swig_file ( ${SOURCEFILE} )
  if ( ${ARGC} GREATER 2 )
    set ( SWIG_MODULE_${MODULENAME}_EXTRA_DEPS ${ARGN} )
  endif ()

  set ( swig_other_sources )
  foreach ( it ${ARGN} )
    if ( ${it} MATCHES ".*\\.i$" )
      ot_install_swig_file ( ${it} )
    else ()
      set ( swig_other_sources ${swig_other_sources} "${it}" )
    endif ()
  endforeach ()

  # swig_add_module is deprecated
  if (CMAKE_VERSION VERSION_LESS 3.8)
    swig_add_module (${MODULENAME} python ${SOURCEFILE} ${swig_other_sources} )
  else ()
    swig_add_library (${MODULENAME} LANGUAGE python SOURCES ${SOURCEFILE} ${swig_other_sources})
  endif ()
  swig_link_libraries (${MODULENAME} otmixmod)
  if ( LINK_PYTHON_LIBRARY )
    swig_link_libraries ( ${MODULENAME} ${PYTHON_LIBRARIES} )
  endif ()

  set_target_properties ( ${SWIG_MODULE_${MODULENAME}_REAL_NAME} PROPERTIES NO_SONAME ON )

  list ( APPEND PYTHON_MODULES ${MODULENAME} )
endmacro ( ot_add_python_module )



ot_add_python_module ( ${PACKAGE_NAME} ${PACKAGE_NAME}_module.i
  MixmodCovarianceModelImplementation.i
  MixmodCovarianceModel.i
  Gaussian_pk_L_B.i
  Gaussian_pk_L_Bk.i
  Gaussian_pk_L_C.i
  Gaussian_pk_L_Ck.i
  Gaussian_pk_L_D_Ak_D.i
  Gaussian_pk_L_Dk_A_Dk.i
  Gaussian_pk_L_I.i
  Gaussian_pk_Lk_B.i
  Gaussian_pk_Lk_Bk.i
  Gaussian_pk_Lk_C.i
  Gaussian_pk_Lk_Ck.i
  Gaussian_pk_Lk_D_Ak_D.i
  Gaussian_pk_Lk_Dk_A_Dk.i
  Gaussian_pk_Lk_I.i
  Gaussian_p_L_B.i
  Gaussian_p_L_Bk.i
  Gaussian_p_L_C.i
  Gaussian_p_L_Ck.i
  Gaussian_p_L_D_Ak_D.i
  Gaussian_p_L_Dk_A_Dk.i
  Gaussian_p_L_I.i
  Gaussian_p_Lk_B.i
  Gaussian_p_Lk_Bk.i
  Gaussian_p_Lk_C.i
  Gaussian_p_Lk_Ck.i
  Gaussian_p_Lk_D_Ak_D.i
  Gaussian_p_Lk_Dk_A_Dk.i
  Gaussian_p_Lk_I.i
  MixtureFactory.i
  MixtureClassifierFactory.i
  )


foreach ( module ${PYTHON_MODULES} )
  install ( FILES ${CMAKE_CURRENT_BINARY_DIR}/${module}.py
    DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME}
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
    )
  install ( TARGETS _${module}
    LIBRARY DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME}
    )
endforeach ( module )

install ( FILES __init__.py
  DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME}
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  )

install ( FILES ${SWIGFILES}
  DESTINATION ${OTMIXMOD_SWIG_INCLUDE_PATH}
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  )
