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

#ifndef SWARM_HTTP_HTTPRESPONSEBUILDER_HXX
#define SWARM_HTTP_HTTPRESPONSEBUILDER_HXX

#include "HTTPResponseStatus.hxx"
#include "../commons/HTTPVersion.hxx"
#include "../header/HTTPHeader.hxx"
#include <swarm/http/MediaType.hxx>

#include <map>
#include <string>
#include <memory>

namespace swarm {
    namespace http {
                
        class HTTPResponse;
        class HTTPBody;
        
        /// \brief Class HTTPResponseBuilder
        class HTTPResponseBuilder {
            
        private:
            /// \brief Define HTTP version
            HTTPVersion version_ = HTTPVersion::HTTP10;
            
            /// \brief Response status
            HTTPResponseStatus status_ = HTTPResponseStatus::OK;
            
            /// \brief Headers
            std::map<HTTPHeader, std::string> headers_;
            
            /// \brief HTTP body
            std::shared_ptr<HTTPBody> body_;
            
        public:
            
            /// \brief Set  HTTP version
            /// \param version New HTTP version
            HTTPResponseBuilder & version(HTTPVersion version) {
                this->version_ = version;
                return *this;
            }
            
            /// \brief Set HTTP response status
            /// \param status New HTTP response status
            HTTPResponseBuilder & status(HTTPResponseStatus status) {
                this->status_ = status;
                return *this;
            }
            
            
            /// \brief Add header param
            /// \param header Header to add
            /// \param value Header value
            /// \return Current builder
            HTTPResponseBuilder & addHeaderParam(const HTTPHeader & header, const std::string & value);
            
            /// \brief Set HTTP body
            /// \param body HTTP body
            /// \return Current builder
            HTTPResponseBuilder & body(std::shared_ptr<HTTPBody> body);
            
            /// \brief Encode body with object and media type
            /// \param Entity object to encode using ObjectEncoder<Body>
            template<typename Body>
            HTTPResponseBuilder & entity(const Body & body, MediaType mediaType);
            
        public:
            /// \brief Build HTTP response
            /// \return HTTP response or invalid smart pointer
            HTTPResponse build();
        };
    }
}

#endif // SWARM_HTTP_HTTPRESPONSEBUILDER_HXX

#include "HTTPResponseBuilder.txx"
