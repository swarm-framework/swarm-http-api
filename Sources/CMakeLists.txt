
# Add sources files
set (${PROJECT_NAME}_SOURCES

    swarm/http/message/commons/HTTPVersion.cxx swarm/http/message/commons/HTTPVersion.hxx 
    swarm/http/message/commons/HTTPParam.cxx swarm/http/message/commons/HTTPParam.hxx 
    
    swarm/http/message/header/HTTPHeader.cxx swarm/http/message/header/HTTPHeader.hxx 
    swarm/http/message/header/HTTPHeaders.cxx swarm/http/message/header/HTTPHeaders.hxx

    swarm/http/stream/HTTPStream.hxx
    swarm/http/stream/HTTPStringStream.cxx swarm/http/stream/HTTPStringStream.hxx

    swarm/http/message/body/HTTPBody.cxx swarm/http/message/body/HTTPBody.hxx

    swarm/http/message/request/HTTPMethod.cxx swarm/http/message/request/HTTPMethod.hxx
    swarm/http/message/request/HTTPRequest.cxx swarm/http/message/request/HTTPRequest.hxx
    swarm/http/message/request/HTTPRequestBuilder.cxx swarm/http/message/request/HTTPRequestBuilder.hxx

    swarm/http/message/response/HTTPResponse.hxx swarm/http/message/response/HTTPResponse.hxx
    swarm/http/message/response/HTTPResponseBuilder.cxx swarm/http/message/response/HTTPResponseBuilder.hxx
    swarm/http/message/response/HTTPResponseStatus.cxx swarm/http/message/response/HTTPResponseStatus.hxx


    swarm/http/tools/URIEncoding.cxx swarm/http/tools/URIEncoding.hxx
    swarm/http/tools/CURLTools.cxx swarm/http/tools/CURLTools.hxx
)

# Set includes
include_directories(
    .                           # Current project
)

# Create library
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
target_link_libraries(${PROJECT_NAME}
    swarm-commons
)

# Install exec in bin directory
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
