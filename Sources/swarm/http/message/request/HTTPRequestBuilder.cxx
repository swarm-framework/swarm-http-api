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

#include "HTTPRequestBuilder.hxx"

#include "HTTPRequest.hxx"
#include <swarm/network/IPAddress.hxx>

namespace swarm {
    namespace http {

        // Build HTTP request
        std::shared_ptr<HTTPRequest> HTTPRequestBuilder::build() {
            return std::shared_ptr<HTTPRequest>(
                new HTTPRequest{version_, serverAddress_, method_, path_, uri_, queryParameters_, headers_, body_});
        }

        // Set HTTP version
        HTTPRequestBuilder &HTTPRequestBuilder::version(HTTPVersion version) {
            this->version_ = version;
            return *this;
        }

        // Set server address
        HTTPRequestBuilder &HTTPRequestBuilder::serverAddress(std::shared_ptr<network::IPAddress> serverAddress) {
            this->serverAddress_ = serverAddress;
            return *this;
        }

        // Set HTTP method
        HTTPRequestBuilder &HTTPRequestBuilder::method(const HTTPMethod & method) {
            this->method_ = method;
            return *this;
        }
        // Set HTTP path
        HTTPRequestBuilder &HTTPRequestBuilder::path(const std::string &path) {
            this->path_ = path;
            return *this;
        }

        // Set URI string
        HTTPRequestBuilder &HTTPRequestBuilder::uri(const std::string &uri) {
            this->uri_ = uri;
            return *this;
        }
        
        // Set query string
        HTTPRequestBuilder &HTTPRequestBuilder::addQueryString(const std::string & query) {
            this->query_ = query;
            
            return *this;
        }
        
        // Add query param to the request
        HTTPRequestBuilder &HTTPRequestBuilder::addQueryParam(std::shared_ptr<HTTPParam> param) {
            if (param) {
                queryParameters_[param->key()] = param;
            }
            return *this;
        }

        // Add header param
        HTTPRequestBuilder &HTTPRequestBuilder::addHeaderParam(const HTTPHeader &header, const std::string &value) {
            headers_[header] = value;
            return *this;
        }
        
        // Set HTTP body
        HTTPRequestBuilder & HTTPRequestBuilder::body(std::shared_ptr<HTTPBody> body) {
            this->body_ = body;
            return *this;
        }
    }
}
