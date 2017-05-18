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

#ifndef SWARM_HTTP_HTTPVERSION_HXX
#define SWARM_HTTP_HTTPVERSION_HXX

#include <ostream>
#include <string>

namespace swarm {
    namespace http {

        /// \brief Enum to define HTTP version
        enum class HTTPVersion {

            /// \brief Old HTTP protocol
            HTTP10,

            /// \brief Current HTTP protocol
            HTTP11,

            /// \brief Futur HTTP protocol
            HTTP20
        };

        namespace HTTPVersions {

            /// \brief Get label from HTTPVersion
            /// \return String containing label or UNKNOWN
            std::string label(HTTPVersion version);

            /// \brief Get HTTPVersion from a string or throw runtime exception
            /// \param str STring containing HTTPVersion
            /// \return HTTPVersion or std::runtime_error
            HTTPVersion get(const std::string &str);
        }

        // Override ostream for HTTPVersion
        std::ostream &operator<<(std::ostream &os, const HTTPVersion &version);
    }
}

#endif // SWARM_HTTP_HTTPVERSION_HXX
