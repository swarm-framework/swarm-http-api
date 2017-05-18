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

#ifndef SWARM_HTTP_URIENCODING_HXX
#define SWARM_HTTP_URIENCODING_HXX

#include <string>

namespace swarm {
    namespace http {
        
        /// \brief Utility class for URIEncoding
        struct URIEncoding {
            
            URIEncoding() = delete;
            
            /// \brief URL encode a string
            /// \param str Original string
            /// \return Encoded string
            static std::string encode(const std::string & str);
            
            /// \brief URL decode a string
            /// \param str URL encoded string
            /// \param decoded string
            static std::string decode(const std::string & str);
        };
    }
}

#endif // SWARM_HTTP_URIENCODING_HXX
