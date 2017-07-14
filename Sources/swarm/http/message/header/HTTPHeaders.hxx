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
#include <string>
#include <map>

#include "HTTPHeader.hxx"

namespace swarm {
    namespace http {

        /// \brief Class HTTPHeaders
        class HTTPHeaders {
            
        private:
            
            /// \return all headers map
            static std::map<std::string, std::shared_ptr<HTTPHeader>> & allHeaders();
            
        public:
            
            /// \brief // Get or create header from string
            /// \param key Header key
            /// \return Header pointer
            static std::shared_ptr<HTTPHeader> get(const std::string & key);
        };
    }
}

#endif // SWARM_HTTP_HTTPHEADERS_HXX
