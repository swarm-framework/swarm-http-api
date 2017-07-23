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

#ifndef SWARM_HTTP_DEFAULTHTTPINPUTSTREAM_HXX
#define SWARM_HTTP_DEFAULTHTTPINPUTSTREAM_HXX

#include <istream>
#include <memory>
#include "HTTPInputStream.hxx"

namespace swarm {
    namespace http {

        /// \brief Define default istream reader
        class DefaultHTTPInputStream : public HTTPInputStream {

          private:
            /// \brief string stream
            std::istream & stream_;

        public:
            /// \brief Constructor with istream
            /// \param stream Input stream
            DefaultHTTPInputStream(std::istream & stream);

          public:
            // Overide read
            virtual std::streamsize read(std::byte *s, std::streamsize n) override;
        };
    }
}

#endif // SWARM_HTTP_DEFAULTHTTPINPUTSTREAM_HXX
