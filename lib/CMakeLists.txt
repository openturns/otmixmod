
add_subdirectory ( include )
add_subdirectory ( src )
add_subdirectory ( test )

install ( FILES ${HEADERFILES}
          DESTINATION ${OTMIXMOD_INCLUDE_PATH}/${PACKAGE_NAME}
          PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
        )
        
        
