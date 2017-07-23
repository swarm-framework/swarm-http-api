/*
 * Copyright 2017 dami <email>
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

#ifndef SWARM_HTTP_HTTPOUTPUTSTREAM_HXX
#define SWARM_HTTP_HTTPOUTPUTSTREAM_HXX

#include "../HTTPStream.hxx"

namespace swarm {
    namespace http {

        /// \brief Class HTTPOutputStream
        struct HTTPOutputStream {
            
            /// \brief Method used to write stream
            /// \param buffer Input buffer of max streamsize length
            /// \param streamsize Max stream size
            /// \return Number of byte writed, 0 for end of stream
            virtual std::streamsize write(std::byte *buffer, std::streamsize n) = 0;

            // Virtual constructor for sub-classing
            virtual ~HTTPOutputStream() {}
        };
    }
}

#endif // SWARM_HTTP_HTTPOUTPUTSTREAM_HXX
