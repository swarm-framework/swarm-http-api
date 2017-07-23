# Set minimum version of CMake.
cmake_minimum_required(VERSION 3.8)

# Set variables:
#   * PROJECT_NAME
#   * PROJECT_VERSION
project(swarm-http-api VERSION 0.1.0)

# Include config
include(Config/config.cmake)

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
    
    Sources/swarm/http/stream/input/HTTPInputStream.hxx
    Sources/swarm/http/stream/input/DefaultHTTPInputStream.cxx Sources/swarm/http/stream/input/DefaultHTTPInputStream.hxx
    
    Sources/swarm/http/stream/output/HTTPOutputStream.hxx
    Sources/swarm/http/stream/output/DefaultHTTPOutputStream.cxx Sources/swarm/http/stream/output/DefaultHTTPOutputStream.hxx

    Sources/swarm/http/message/body/HTTPBody.cxx Sources/swarm/http/message/body/HTTPBody.hxx

    Sources/swarm/http/message/request/HTTPMethod.cxx Sources/swarm/http/message/request/HTTPMethod.hxx
    Sources/swarm/http/message/request/HTTPRequest.cxx Sources/swarm/http/message/request/HTTPRequest.hxx
    Sources/swarm/http/message/request/HTTPRequestBuilder.cxx Sources/swarm/http/message/request/HTTPRequestBuilder.hxx

    Sources/swarm/http/message/response/HTTPResponse.hxx Sources/swarm/http/message/response/HTTPResponse.hxx
    Sources/swarm/http/message/response/HTTPResponseBuilder.cxx Sources/swarm/http/message/response/HTTPResponseBuilder.hxx Sources/swarm/http/message/response/HTTPResponseBuilder.txx
    Sources/swarm/http/message/response/HTTPResponseStatus.cxx Sources/swarm/http/message/response/HTTPResponseStatus.hxx

    Sources/swarm/http/mapping/ProviderRegistry.cxx Sources/swarm/http/mapping/ProviderRegistry.hxx
    
    Sources/swarm/http/mapping/encoder/EncoderProviderFactory.hxx 
    Sources/swarm/http/mapping/encoder/DefaultEncoderProviderFactory.hxx Sources/swarm/http/mapping/encoder/DefaultEncoderProviderFactory.txx
    
    Sources/swarm/http/mapping/decoder/DecoderProviderFactory.hxx
    Sources/swarm/http/mapping/decoder/DefaultDecoderProviderFactory.hxx Sources/swarm/http/mapping/decoder/DefaultDecoderProviderFactory.txx

    Sources/swarm/http/tools/URIEncoding.cxx Sources/swarm/http/tools/URIEncoding.hxx
    Sources/swarm/http/tools/CURLTools.cxx Sources/swarm/http/tools/CURLTools.hxx
)

# Global includes. Used by all targets
target_include_directories(
    swarm-http-api
        
    PRIVATE
        ${cxx-log_INCLUDE_DIR}
        ${swarm-commons_INCLUDE_DIR}
        ${swarm-mapping_INCLUDE_DIR}
)

# Link library
target_link_libraries(
    swarm-http-api
    
    swarm-commons
    swarm-mapping
    ${CURL_LIBRARIES}
)

# Include build
include(Config/build.cmake)

# Include test
add_subdirectory(Tests)
