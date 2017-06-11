
# Find Curl
find_package(CURL REQUIRED)

# Include sub projects
find_dependencies(cxx-log)
find_dependencies(swarm-commons)
find_dependencies(swarm-mapping)

# Create targets
add_library(swarm-http-api

    Sources/swarm/http/message/commons/HTTPVersion.cxx Sources/swarm/http/message/commons/HTTPVersion.hxx 
    Sources/swarm/http/message/commons/HTTPParam.cxx Sources/swarm/http/message/commons/HTTPParam.hxx 
    
    Sources/swarm/http/message/header/HTTPHeader.cxx Sources/swarm/http/message/header/HTTPHeader.hxx 
    Sources/swarm/http/message/header/HTTPHeaders.cxx Sources/swarm/http/message/header/HTTPHeaders.hxx

    Sources/swarm/http/stream/HTTPStream.hxx
    Sources/swarm/http/stream/HTTPStringStream.cxx Sources/swarm/http/stream/HTTPStringStream.hxx

    Sources/swarm/http/message/body/HTTPBody.cxx Sources/swarm/http/message/body/HTTPBody.hxx

    Sources/swarm/http/message/request/HTTPMethod.cxx Sources/swarm/http/message/request/HTTPMethod.hxx
    Sources/swarm/http/message/request/HTTPRequest.cxx Sources/swarm/http/message/request/HTTPRequest.hxx
    Sources/swarm/http/message/request/HTTPRequestBuilder.cxx Sources/swarm/http/message/request/HTTPRequestBuilder.hxx

    Sources/swarm/http/message/response/HTTPResponse.hxx Sources/swarm/http/message/response/HTTPResponse.hxx
    Sources/swarm/http/message/response/HTTPResponseBuilder.cxx Sources/swarm/http/message/response/HTTPResponseBuilder.hxx Sources/swarm/http/message/response/HTTPResponseBuilder.txx
    Sources/swarm/http/message/response/HTTPResponseStatus.cxx Sources/swarm/http/message/response/HTTPResponseStatus.hxx


    Sources/swarm/http/tools/URIEncoding.cxx Sources/swarm/http/tools/URIEncoding.hxx
    Sources/swarm/http/tools/CURLTools.cxx Sources/swarm/http/tools/CURLTools.hxx
)

# Properties of targets

# Add definitions for targets
# Values:
#   * Debug: -DSWAM_MAPPING_DEBUG=1
#   * Release: -DSWAM_MAPPING_DEBUG=0
#   * other: -DSWAM_MAPPING_DEBUG=0
target_compile_definitions(swarm-http-api  PUBLIC "SWAM_MAPPING_DEBUG=$<CONFIG:Debug>")

# Generate headers:
include(GenerateExportHeader)
generate_export_header(swarm-http-api)

# Global includes. Used by all targets
target_include_directories(
    swarm-http-api
    
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Sources>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        
    PRIVATE
        ${cxx-log_INCLUDE_DIR}
        ${swarm-commons_INCLUDE_DIR}
)

target_link_libraries(
    swarm-http-api
    swarm-commons
    swarm-mapping
    ${CURL_LIBRARIES}
)

set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Configuration
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Note: PROJECT_VERSION is used as a VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * targets_export_name
#   * PROJECT_NAME
configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# Targets:
#   * <prefix>/lib/${target}.a
#   * header location after install: <prefix>/include/*.hxx
#   * headers can be included by C++ code `#include <project/*.hxx>`
install(
    TARGETS swarm-http-api
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

# Headers:
#   * Sources/${target}/*.hxx -> <prefix>/include/${target}/*.hxx
install(
    DIRECTORY "Sources/swarm"
    DESTINATION "${include_install_dir}"
    FILES_MATCHING PATTERN "*.[h;t]xx"
)

# Export headers:
#   * ${CMAKE_CURRENT_BINARY_DIR}/${target}_export.h -> <prefix>/include/${target}_export.h
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/swarm-http-api_export.h"
    DESTINATION "${include_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/${project}/${Target}Config.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/${project}/${Target}Targets.cmake
install(
    EXPORT "${targets_export_name}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)