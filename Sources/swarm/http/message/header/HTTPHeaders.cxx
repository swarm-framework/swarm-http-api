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

#include "HTTPHeaders.hxx"

namespace swarm {
    namespace http {

        /// \return all headers map
        std::map<std::string, std::shared_ptr<HTTPHeader>> &HTTPHeaders::allHeaders() {
            static std::map<std::string, std::shared_ptr<HTTPHeader>> ALL_HEADERS{};
            return ALL_HEADERS;
        }

        // Get or create header from string
        std::shared_ptr<HTTPHeader> HTTPHeaders::get(const std::string &key) {

            auto & headers = allHeaders();
            auto it = headers.find(key);
            if (it == headers.end()) {
                auto header = std::make_shared<HTTPHeader>(key);
                headers[key] = header;
                return header;
            } else {
                return it->second;
            }
        }
    }
}
