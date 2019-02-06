
include (${SWIG_USE_FILE})
include (TargetLinkLibrariesWithDynamicLookup)

include_directories ( ${OPENTURNS_SWIG_INCLUDE_DIRS} )
add_definitions( ${OPENTURNS_SWIG_DEFINITIONS} )
include_directories ( ${INTERNAL_INCLUDE_DIRS} )
include_directories ( ${PYTHON_INCLUDE_DIRS} )

add_custom_target( generate_docstrings )

macro ( ot_add_python_module MODULENAME SOURCEFILE )
  set_source_files_properties ( ${SOURCEFILE} PROPERTIES CPLUSPLUS ON )
  set_source_files_properties ( ${SOURCEFILE} PROPERTIES SWIG_MODULE_NAME ${MODULENAME} )
  ot_install_swig_file ( ${SOURCEFILE} )
  if (${ARGC} GREATER 2)
    set (SWIG_MODULE_${MODULENAME}_python_EXTRA_DEPS ${ARGN})
    list (APPEND SWIG_MODULE_${MODULENAME}_python_EXTRA_DEPS generate_docstrings)
  endif ()

  set ( swig_other_sources )
  foreach ( it ${ARGN} )
    if ( ${it} MATCHES ".*\\.i$" )
      ot_install_swig_file ( ${it} )
    elseif(${it} MATCHES ".*_doc\\.i\\.in$")
      # handle docstring generation
      set (DOCSTRING_IN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${it})
      get_filename_component ( DOCSTRING_FILE_BASENAME ${DOCSTRING_IN_FILE} NAME_WE )
      add_custom_target ( generate_${DOCSTRING_FILE_BASENAME}
                          COMMAND ${CMAKE_COMMAND} -DDOCSTRING_IN_FILE=${DOCSTRING_IN_FILE} -DDOCSTRING_FILE=${CMAKE_CURRENT_BINARY_DIR}/${DOCSTRING_FILE_BASENAME}.i -P ${CMAKE_SOURCE_DIR}/cmake/escape_backslash_x4.cmake
                          DEPENDS ${DOCSTRING_IN_FILE} )
      add_dependencies ( generate_docstrings generate_${DOCSTRING_FILE_BASENAME} )
      list ( APPEND SWIGFILES ${CMAKE_CURRENT_BINARY_DIR}/${DOCSTRING_FILE_BASENAME}.i )
    else ()
      set ( swig_other_sources ${swig_other_sources} "${it}" )
    endif ()
  endforeach ()

  # swig_add_module is deprecated
  if (CMAKE_VERSION VERSION_LESS 3.8)
    swig_add_module (${MODULENAME}_python python ${SOURCEFILE} ${swig_other_sources} )
  else ()
    swig_add_library (${MODULENAME}_python LANGUAGE python SOURCES ${SOURCEFILE} ${swig_other_sources})
  endif ()

  # UseSWIG generates now standard target names
  if (CMAKE_VERSION VERSION_LESS 3.13)
    set (module_target ${SWIG_MODULE_${MODULENAME}_python_REAL_NAME})
  else ()
    set (module_target ${MODULENAME}_python)
  endif ()

  swig_link_libraries (${MODULENAME}_python otmixmod)

  target_link_libraries_with_dynamic_lookup (${module_target} ${PYTHON_LIBRARIES})

  set_target_properties (${module_target} PROPERTIES OUTPUT_NAME ${MODULENAME})

  if (CMAKE_VERSION VERSION_LESS 3.13)
    set_target_properties (${module_target} PROPERTIES PREFIX "_")
  endif ()

  if (CMAKE_VERSION VERSION_LESS 3.1)
    set_target_properties (${module_target} PROPERTIES NO_SONAME ON)
  endif ()

  install (FILES ${CMAKE_CURRENT_BINARY_DIR}/${MODULENAME}.py
           DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME})
  install (TARGETS ${module_target}
            LIBRARY DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME})

  list (APPEND OTMIXMOD_PYTHON_MODULES ${MODULENAME})
endmacro ()


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



install ( FILES __init__.py
          DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME}
        )

install ( FILES ${SWIGFILES}
	DESTINATION ${OTMIXMOD_SWIG_INCLUDE_DIRS}
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  )
