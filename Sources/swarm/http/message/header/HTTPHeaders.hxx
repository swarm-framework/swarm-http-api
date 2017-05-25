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

#ifndef SWARM_HTTP_HTTPHEADERS_HXX
#define SWARM_HTTP_HTTPHEADERS_HXX

#include <memory>
#include "HTTPHeader.hxx"

namespace swarm {
    namespace http {

        /// \brief Class HTTPHeaders
        struct HTTPHeaders {
            
            static std::shared_ptr<HTTPHeader> get(const std::string & key) {
                // Use map and upper case key to store and reuse registered headers
                return std::make_shared<HTTPHeader>(key);
            }
        };
    }
}

#endif // SWARM_HTTP_HTTPHEADERS_HXX
