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

#ifndef SWARM_HTTP_HTTPRESPONSE_HXX
#define SWARM_HTTP_HTTPRESPONSE_HXX

#include "../commons/HTTPVersion.hxx"
#include "../header/HTTPHeader.hxx"
#include "HTTPResponseStatus.hxx"
#include <map>
#include <memory>

namespace swarm {
    namespace http {

        class HTTPBody;

        /// \brief Define HTTP response
        class HTTPResponse {

            // Define firend to build usage
            friend class HTTPResponseBuilder;

          private:
            /// \brief Define HTTP version
            HTTPVersion version_;

            /// \brief HTTP response status
            HTTPResponseStatus status_;

            /// \brief Request headers
            std::map<HTTPHeader, std::string> headers_;

            /// \brief Request body (for POST or PUT method)
            std::shared_ptr<HTTPBody> body_;

          public:
            /// \brief Move constructor
            /// \param other Other response
            HTTPResponse(HTTPResponse &&other)
                : version_(other.version_), status_(std::move(other.status_)),
                  headers_(std::move(other.headers())), body_(other.body_) {}

          private:
            /// \brief Constructor
            /// \param version HTTP protocol version
            /// \param status HTTP response status
            /// \param headers HTTP headers
            /// \param body HTTP body
            HTTPResponse(HTTPVersion version, HTTPResponseStatus status, std::map<HTTPHeader, std::string> headers,
                         std::shared_ptr<HTTPBody> body)
                : version_(version), status_(status), headers_(headers), body_(body) {}

          public:

            /// \return HTTP version
            HTTPVersion version() const { return version_; }

            /// \return HTTP response status
            const HTTPResponseStatus &status() const { return status_; }

            /// \return HTTP headers
            const std::map<HTTPHeader, std::string> &headers() const { return headers_; }

            /// \return HTTP body
            std::shared_ptr<HTTPBody> body() { return body_; }
        };
    }
}

#endif // SWARM_HTTP_HTTPRESPONSE_HXX
