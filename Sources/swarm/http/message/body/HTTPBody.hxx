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

#ifndef SWARM_HTTP_HTTPBODY_HXX
#define SWARM_HTTP_HTTPBODY_HXX

#include "../../stream/HTTPStream.hxx"
#include <memory>
#include <swarm/http/MediaType.hxx>

namespace swarm {
    namespace http {

        /// \brief Define an HTTP body for request and response
        template<class STREAM>
        class HTTPBody {

          private:
            /// \brief Media type defining the content type
            MediaType mediaType_;

            /// \brief Stream containing data content
            std::shared_ptr<STREAM> stream_;

            /// \brief Content length, negative for Chunked stream
            streamLength length_;

          public:
            /// \brief Constructor with media-type, stream and length
            /// \param mediaType Content type
            /// \param stream Stream
            /// \param length Stream length
            HTTPBody(MediaType mediaType, std::shared_ptr<STREAM> stream, streamLength length = -1ULL)
                : mediaType_(mediaType), stream_(stream), length_(length) {}

            HTTPBody(const HTTPBody &) = delete;

            /// \brief Move constructor
            /// \param body Body to move
            HTTPBody(HTTPBody &&body)
                : mediaType_(std::move(body.mediaType_)), stream_(std::move(body.stream_)), length_(body.length_) {}

          public:
            /// \brief Content type
            /// \return Media type defining content-type
            MediaType mediaType() const { return mediaType_; }

            /// \brief Content length
            /// \return Body length or negative for chuncked stream
            streamLength length() const { return length_; }

            /// \brief Stream containing data
            /// \return Stream
            STREAM &stream() { return *stream_; }
        };
    }
}

#endif // SWARM_HTTP_HTTPBODY_HXX
