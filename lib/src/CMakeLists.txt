ot_add_current_dir_to_include_dirs ()

ot_add_source_file ( MixtureFactory.cxx )

ot_install_header_file ( MixtureFactory.hxx )

include_directories ( ${INTERNAL_INCLUDE_DIRS} )

add_library ( otmixmod SHARED ${SOURCEFILES} )
if ( NOT DEFINED LIB_VERSION ) 
  set ( LIB_VERSION 0.0.0 )
endif ()
if ( NOT DEFINED LIB_SOVERSION ) 
  set ( LIB_SOVERSION 0 )
endif ()
set_target_properties ( otmixmod PROPERTIES VERSION ${LIB_VERSION} )
set_target_properties ( otmixmod PROPERTIES SOVERSION ${LIB_SOVERSION} )
target_link_libraries (otmixmod ${OPENTURNS_LIBRARY})

target_include_directories(otmixmod PRIVATE ${MIXMOD_INCLUDE_DIRS})
target_link_libraries (otmixmod ${MIXMOD_LIBRARIES})

set_target_properties (otmixmod PROPERTIES UNITY_BUILD OFF)

# Add targets to the build-tree export set
export (TARGETS otmixmod FILE ${PROJECT_BINARY_DIR}/OTMixmod-Targets.cmake)

# Install the export set for use with the install-tree
install(EXPORT OTMixmod-Targets
        DESTINATION "${OTMIXMOD_CONFIG_CMAKE_PATH}"
        COMPONENT Development)

install(TARGETS otmixmod
        EXPORT  OTMixmod-Targets 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${OTMIXMOD_LIBRARY_PATH}
        ARCHIVE DESTINATION ${OTMIXMOD_LIBRARY_PATH}
)

