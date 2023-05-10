
include_directories (${OPENTURNS_INCLUDE_DIRS})
include_directories (${OPENTURNS_SWIG_INCLUDE_DIRS})
add_definitions (${OPENTURNS_SWIG_DEFINITIONS})
include_directories (${INTERNAL_INCLUDE_DIRS})

# allows one to pass compile flags like -O1 to reduce memory usage
set (SWIG_COMPILE_FLAGS "" CACHE STRING "C++ compiler flags used for wrapper code")

macro (ot_add_python_module MODULENAME SOURCEFILE)
  set_source_files_properties (${SOURCEFILE} PROPERTIES CPLUSPLUS ON)
  set_source_files_properties (${SOURCEFILE} PROPERTIES SWIG_MODULE_NAME ${MODULENAME})
  ot_install_swig_file (${SOURCEFILE})
  if (${ARGC} GREATER 2)
    set (SWIG_MODULE_${MODULENAME}_python_EXTRA_DEPS ${ARGN})
  endif ()

  set (swig_other_sources)
  set (docstring_sources)
  foreach (it ${ARGN})
    if (${it} MATCHES ".*\\.i$")
      ot_install_swig_file (${it})
    elseif (${it} MATCHES ".*_doc\\.i\\.in$")
      list (APPEND docstring_sources ${it})

      get_filename_component (DOCSTRING_FILE_BASENAME ${it} NAME_WE)
      ot_install_swig_file (${CMAKE_CURRENT_BINARY_DIR}/${DOCSTRING_FILE_BASENAME}.i)
    else ()
      list (APPEND swig_other_sources "${it}")
    endif ()
  endforeach ()

  # https://github.com/swig/swig/issues/1273
  option (SWIG_FORCE_DOUBLE_ESCAPE_BACKSLASH "Force double escaping of backslashes" OFF)
  mark_as_advanced (SWIG_FORCE_DOUBLE_ESCAPE_BACKSLASH)
  set (TIMES x1)
  if ((SWIG_VERSION VERSION_LESS 4) OR SWIG_FORCE_DOUBLE_ESCAPE_BACKSLASH)
    set (TIMES x2)
  endif ()

  # handle docstring generation
  add_custom_target (generate_${MODULENAME}_docstrings
                      COMMAND ${CMAKE_COMMAND} -DDOCSTRING_SOURCES="${docstring_sources}"
                      -DCURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR} -DTIMES=${TIMES}
                      -P ${CMAKE_SOURCE_DIR}/cmake/escape_backslash.cmake
                      DEPENDS ${docstring_sources})
  list (APPEND SWIG_MODULE_${MODULENAME}_python_EXTRA_DEPS generate_${MODULENAME}_docstrings)

  # swig_add_module is deprecated
  swig_add_library (${MODULENAME}_python LANGUAGE python SOURCES ${SOURCEFILE} ${swig_other_sources})

  # UseSWIG generates now standard target names
  set (module_target ${MODULENAME}_python)

  swig_link_libraries (${MODULENAME}_python otmixmod)
  target_include_directories (${MODULENAME}_python PRIVATE ${Python_INCLUDE_DIRS})

  if (TARGET Python::Module)
    target_link_libraries (${module_target} Python::Module)
  else ()
    target_link_libraries_with_dynamic_lookup (${module_target} ${Python_LIBRARIES})
  endif ()

  set_target_properties (${module_target} PROPERTIES OUTPUT_NAME ${MODULENAME})

  set_target_properties (${module_target} PROPERTIES COMPILE_FLAGS "${SWIG_COMPILE_FLAGS}")

  set_target_properties (${module_target} PROPERTIES UNITY_BUILD OFF)

  install (FILES ${CMAKE_CURRENT_BINARY_DIR}/${MODULENAME}.py
           DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME})
  install (TARGETS ${module_target}
            LIBRARY DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME})

  list (APPEND OTMIXMOD_PYTHON_MODULES ${MODULENAME})
endmacro ()


ot_add_python_module ( ${PACKAGE_NAME} ${PACKAGE_NAME}_module.i
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

# wheel files
configure_file (METADATA.in METADATA @ONLY)
configure_file (WHEEL.in WHEEL @ONLY)
install (DIRECTORY DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME}-${PACKAGE_VERSION}.dist-info)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/METADATA ${CMAKE_CURRENT_BINARY_DIR}/WHEEL
	DESTINATION ${OTMIXMOD_PYTHON_MODULE_PATH}/${PACKAGE_NAME}-${PACKAGE_VERSION}.dist-info)
