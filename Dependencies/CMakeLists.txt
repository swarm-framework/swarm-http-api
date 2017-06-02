if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/cxx-log/CMakeLists.txt)

    if(NOT TARGET cxx-log)
    
        # Include cxx-log
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log/Sources)
        
    endif()

endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/swarm-commons/CMakeLists.txt)

    if(NOT TARGET swarm-commons)

        # Include swarm-commons
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/swarm-commons)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/swarm-commons/Sources)

    endif()

endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/swarm-mapping/CMakeLists.txt)

    if(NOT TARGET swarm-mapping)

        # Include swarm-mapping
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/swarm-mapping)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/swarm-mapping/Sources)

    endif()

endif()

# --- Find Curl package ---

# Find Curl
find_package(CURL REQUIRED)

