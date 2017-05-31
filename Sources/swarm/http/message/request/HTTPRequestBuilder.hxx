/*
 * Copyright 2017 Dami <contact@damiengiron.me>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef SWARM_HTTP_HTTPREQUESTBUILDER_HXX
#define SWARM_HTTP_HTTPREQUESTBUILDER_HXX

#include "../commons/HTTPVersion.hxx"
#include "../header/HTTPHeader.hxx"
#include "HTTPMethod.hxx"

#include <memory>
#include <map>

namespace swarm {
    namespace http {

        class HTTPRequest;
        class HTTPParam;
        class HTTPBody;
        namespace network {
            class IPAddress;
        }

        /// \brief Class HTTPRequestBuilder
        class HTTPRequestBuilder {

          private:
            /// \brief Define HTTP version
            HTTPVersion version_ = HTTPVersion::HTTP10;

            /// \brief Server address
            std::shared_ptr<network::IPAddress> serverAddress_;

            /// \brief HTTP method
            HTTPMethod method_ = HTTPMethod::GET;
            
            /// \brief Define request path
            std::string path_;
            
            /// \brief URI string
            std::string uri_;
            
            /// \brief all query parameters
            std::map<std::string, std::shared_ptr<HTTPParam>> queryParameters_;
            
            /// \brief Headers
            std::map<HTTPHeader, std::string> headers_;
            
            /// \brief HTTP body
            std::shared_ptr<HTTPBody> body_;

          public:
            /// \brief Set HTTP version
            /// \param version New HTTP version
            /// \return Current builder
            HTTPRequestBuilder &version(HTTPVersion version);

            /// \brief Set server address
            /// \param serverAddress New server address
            /// \return Current builder
            HTTPRequestBuilder &serverAddress(std::shared_ptr<network::IPAddress> serverAddress);

            /// \brief Set HTTP method
            /// \param method New HTTP method
            /// \return Current builder
            HTTPRequestBuilder &method(const HTTPMethod method);
            
            /// \brief Set HTTP path
            /// \param path New HTTP path
            /// \return Current builder
            HTTPRequestBuilder &path(const std::string & path);
            
            /// \brief Set URI string
            /// \param uri URI string
            /// \return Current builder
            HTTPRequestBuilder &uri(const std::string & uri);
            
            /// \brief Add query param to the request
            /// \param param HTTP Param 
            /// \return Current builder
            HTTPRequestBuilder & addQueryParam(std::shared_ptr<HTTPParam> param);
            
            /// \brief Add header param
            /// \param header Header to add
            /// \param value Header value
            /// \return Current builder
            HTTPRequestBuilder & addHeaderParam(const HTTPHeader & header, const std::string & value);
            
            /// \brief Set HTTP body
            /// \param body HTTP body
            /// \return Current builder
            HTTPRequestBuilder & body(std::shared_ptr<HTTPBody> body);

          public:
            /// \brief Build HTTP request
            /// \return HTTP request or invalid smart pointer
            std::shared_ptr<HTTPRequest> build();
        };
    }
}

#endif // SWARM_HTTP_HTTPREQUESTBUILDER_HXX
