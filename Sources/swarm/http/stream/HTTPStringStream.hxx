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

#ifndef SWARM_HTTP_HTTPSTRINGSTREAM_HXX
#define SWARM_HTTP_HTTPSTRINGSTREAM_HXX

#include "HTTPStream.hxx"
#include <sstream>
#include <memory>

namespace swarm {
    namespace http {

        /// \brief Define string stream reader
        class HTTPStringStream : public HTTPStream {

          private:
            /// \brief string stream
            std::stringstream sstream_;

        public:
            ///\brief Constructor with Stringstream
            /// \param str Stringstream
            HTTPStringStream(std::stringstream && stringstream);
            
            ///\brief Constructor with string
            /// \param str String used like a stream
            HTTPStringStream(const std::string &str);

          public:
            // Overide read
            virtual std::streamsize read(char *s, std::streamsize n) override;
            
        public:
            
            /// \brief Create stream pointer form string stream
            /// \param stringstream Stream to move
            /// \return Stream pointer
            static std::shared_ptr<HTTPStream> get(std::stringstream && stringstream);
            
            /// \brief Create stream pointer form string
            /// \param str String
            /// \return Stream pointer
            static std::shared_ptr<HTTPStream> get(const std::string & str);
        };
    }
}

#endif // SWARM_HTTP_HTTPSTRINGSTREAM_HXX
