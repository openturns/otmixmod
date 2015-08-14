
add_subdirectory ( src )
add_subdirectory ( test )

install ( FILES ${HEADERFILES}
          DESTINATION ${OTMIXMOD_INCLUDE_PATH}
          PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
        )
        
        