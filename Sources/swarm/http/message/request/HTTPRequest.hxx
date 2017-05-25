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

#ifndef SWARM_HTTP_HTTPREQUEST_HXX
#define SWARM_HTTP_HTTPREQUEST_HXX

#include "../commons/HTTPParam.hxx"
#include "../commons/HTTPVersion.hxx"
#include "../header/HTTPHeader.hxx"
#include "HTTPMethod.hxx"
#include <map>
#include <swarm/network/IPAddress.hxx>

namespace swarm {
    namespace http {

        class HTTPBody;
        
        /// \brief Define HTTP request
        class HTTPRequest {

            // Define firend to build usage
            friend class HTTPRequestBuilder;

          private:
            /// \brief Define HTTP version
            HTTPVersion version_;

            /// \brief Server address
            std::shared_ptr<network::IPAddress> serverAddress_;

            /// \brief HTTP method
            HTTPMethod method_;

            /// \brief Request path
            std::string path_;

            /// \brief URI string
            std::string uri_;

            /// \brief Parameters
            std::map<std::string, std::shared_ptr<HTTPParam>> queryParams_;

            /// \brief Request headers
            std::map<HTTPHeader, std::string> headers_;
            
            /// \brief Request body (for POST or PUT method)
            std::shared_ptr<HTTPBody> body_;

          public:
            /// \brief Move constructor
            /// \param other Other object
            HTTPRequest(HTTPRequest &&other)
                : version_(other.version_), serverAddress_(other.serverAddress_), method_(other.method_),
                  path_(std::move(other.path_)), uri_(std::move(other.uri_)),
                  queryParams_(std::move(other.queryParams_)), 
                  headers_(std::move(other.headers_)), body_(other.body_) {}

          private:
            /// \brief Create HTTP request
            /// \param version HTTP version
            /// \param serverAddress Server address
            /// \param method HTTP method
            /// \param path Request path
            /// \param uri URI string
            /// \param queryParams All query params
            /// \param headers Headers
            HTTPRequest(HTTPVersion version, std::shared_ptr<network::IPAddress> serverAddress,
                        const HTTPMethod & method, const std::string &path, const std::string uri,
                        const std::map<std::string, std::shared_ptr<HTTPParam>> &queryParams,
                        const std::map<HTTPHeader, std::string> &headers,
                        std::shared_ptr<HTTPBody> body
                       )
                : version_(version), serverAddress_(serverAddress), method_(method), path_(path), uri_(uri),
                queryParams_(queryParams), headers_(headers), body_(body) {}

          public:
            /// \return Retrieve HTTP version
            HTTPVersion version() const { return version_; }

            /// \brief Get server address
            /// \return IP address or invalid pointer
            const network::IPAddress &serverAddress() const { return *serverAddress_; }

            /// \return Get request method
            const HTTPMethod &method() const { return method_; }

            /// \return Request path
            const std::string &path() const { return path_; }
            
            /// \return URI string
            const std::string &uri() const { return uri_; }
            
            /// \return Request headers
            const std::map<HTTPHeader, std::string>& headers() const { return headers_; }

            /// \return all query parameters as a map
            const std::map<std::string, std::shared_ptr<HTTPParam>> &queryParams() const { return queryParams_; }
            
            /// \return If exists, return body for method POST or PUT and empty pointer for other
            std::shared_ptr<HTTPBody> body() const {
                return body_;
            }
        };
    }
}

#endif // SWARM_HTTP_HTTPREQUEST_HXX
