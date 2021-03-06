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

#include "HTTPResponseBuilder.hxx"

#include "HTTPResponse.hxx"

namespace swarm {
    namespace http {

        // Build HTTP response
        HTTPResponse HTTPResponseBuilder::build() {
            return HTTPResponse{version_, status_, headers_, body_};
        }

        // Add header param
        HTTPResponseBuilder & HTTPResponseBuilder::addHeaderParam(const HTTPHeader & header, const std::string & value) {
            this->headers_[header] = value;
            return *this;
        }

        // HTTP body
        HTTPResponseBuilder & HTTPResponseBuilder::body(std::shared_ptr<HTTPBody> body) {
            this->body_ = body;
            return *this;
        }
    }
}
