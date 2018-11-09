
add_subdirectory ( mixmod )

ot_add_current_dir_to_include_dirs ()

ot_add_source_file ( Gaussian_pk_L_B.cxx )
ot_add_source_file ( Gaussian_pk_L_Bk.cxx )
ot_add_source_file ( Gaussian_pk_L_C.cxx )
ot_add_source_file ( Gaussian_pk_L_Ck.cxx )
ot_add_source_file ( Gaussian_pk_L_D_Ak_D.cxx )
ot_add_source_file ( Gaussian_pk_L_Dk_A_Dk.cxx )
ot_add_source_file ( Gaussian_pk_L_I.cxx )
ot_add_source_file ( Gaussian_pk_Lk_B.cxx )
ot_add_source_file ( Gaussian_pk_Lk_Bk.cxx )
ot_add_source_file ( Gaussian_pk_Lk_C.cxx )
ot_add_source_file ( Gaussian_pk_Lk_Ck.cxx )
ot_add_source_file ( Gaussian_pk_Lk_D_Ak_D.cxx )
ot_add_source_file ( Gaussian_pk_Lk_Dk_A_Dk.cxx )
ot_add_source_file ( Gaussian_pk_Lk_I.cxx )
ot_add_source_file ( Gaussian_p_L_B.cxx )
ot_add_source_file ( Gaussian_p_L_Bk.cxx )
ot_add_source_file ( Gaussian_p_L_C.cxx )
ot_add_source_file ( Gaussian_p_L_Ck.cxx )
ot_add_source_file ( Gaussian_p_L_D_Ak_D.cxx )
ot_add_source_file ( Gaussian_p_L_Dk_A_Dk.cxx )
ot_add_source_file ( Gaussian_p_L_I.cxx )
ot_add_source_file ( Gaussian_p_Lk_B.cxx )
ot_add_source_file ( Gaussian_p_Lk_Bk.cxx )
ot_add_source_file ( Gaussian_p_Lk_C.cxx )
ot_add_source_file ( Gaussian_p_Lk_Ck.cxx )
ot_add_source_file ( Gaussian_p_Lk_D_Ak_D.cxx )
ot_add_source_file ( Gaussian_p_Lk_Dk_A_Dk.cxx )
ot_add_source_file ( Gaussian_p_Lk_I.cxx )
ot_add_source_file ( MixmodCovarianceModel.cxx )
ot_add_source_file ( MixmodCovarianceModelImplementation.cxx )
ot_add_source_file ( MixtureClassifierFactory.cxx )
ot_add_source_file ( MixtureFactory.cxx )

ot_install_header_file ( Gaussian_pk_L_B.hxx )
ot_install_header_file ( Gaussian_pk_L_Bk.hxx )
ot_install_header_file ( Gaussian_pk_L_C.hxx )
ot_install_header_file ( Gaussian_pk_L_Ck.hxx )
ot_install_header_file ( Gaussian_pk_L_D_Ak_D.hxx )
ot_install_header_file ( Gaussian_pk_L_Dk_A_Dk.hxx )
ot_install_header_file ( Gaussian_pk_L_I.hxx )
ot_install_header_file ( Gaussian_pk_Lk_B.hxx )
ot_install_header_file ( Gaussian_pk_Lk_Bk.hxx )
ot_install_header_file ( Gaussian_pk_Lk_C.hxx )
ot_install_header_file ( Gaussian_pk_Lk_Ck.hxx )
ot_install_header_file ( Gaussian_pk_Lk_D_Ak_D.hxx )
ot_install_header_file ( Gaussian_pk_Lk_Dk_A_Dk.hxx )
ot_install_header_file ( Gaussian_pk_Lk_I.hxx )
ot_install_header_file ( Gaussian_p_L_B.hxx )
ot_install_header_file ( Gaussian_p_L_Bk.hxx )
ot_install_header_file ( Gaussian_p_L_C.hxx )
ot_install_header_file ( Gaussian_p_L_Ck.hxx )
ot_install_header_file ( Gaussian_p_L_D_Ak_D.hxx )
ot_install_header_file ( Gaussian_p_L_Dk_A_Dk.hxx )
ot_install_header_file ( Gaussian_p_L_I.hxx )
ot_install_header_file ( Gaussian_p_Lk_B.hxx )
ot_install_header_file ( Gaussian_p_Lk_Bk.hxx )
ot_install_header_file ( Gaussian_p_Lk_C.hxx )
ot_install_header_file ( Gaussian_p_Lk_Ck.hxx )
ot_install_header_file ( Gaussian_p_Lk_D_Ak_D.hxx )
ot_install_header_file ( Gaussian_p_Lk_Dk_A_Dk.hxx )
ot_install_header_file ( Gaussian_p_Lk_I.hxx )
ot_install_header_file ( MixmodCovarianceModel.hxx )
ot_install_header_file ( MixmodCovarianceModelImplementation.hxx )
ot_install_header_file ( MixtureClassifierFactory.hxx )
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

