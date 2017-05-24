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

#ifndef SWARM_HTTP_HTTPSTREAM_HXX
#define SWARM_HTTP_HTTPSTREAM_HXX

#include <ios>

namespace swarm {
    namespace http {

        /// \brief Define HTTP stream
        /// The abstract class define a method to read char (n max) and return readed count
        struct HTTPStream {

            /// \brief define stream length
            using streamLength = unsigned long long;

            /// \brief Method used to read stream
            virtual std::streamsize read(char *s, std::streamsize n) = 0;

            // Virtual constructor for sub-classing
            virtual ~HTTPStream() {}
        };
    }
}

#endif // SWARM_HTTP_HTTPSTREAM_HXX
