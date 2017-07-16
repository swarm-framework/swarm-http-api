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

#ifndef SWARM_HTTP_CURLTOOLS_HXX
#define SWARM_HTTP_CURLTOOLS_HXX

#include <cxx-log/Logger.hxx>

#include <curl/curl.h>
#include <string>

namespace swarm {
    namespace http {

        /// \brief Class CURLTools
        class CURLTools {
            
        private:
            
            // Internal lib curl pointer
            static CURL *curl_;
            
            // Internal logger
            static cxxlog::Logger LOGGER_;
            
        public:
            
            /// \brief URL encode string using curl_easy_escape
            /// \param str String to encode
            /// \return string encoded or ""
            static std::string easy_escape(const std::string & str);
            
            /// \brief URL decode string using curl_easy_unescape
            /// \param str String to decode
            /// \return string decoded or ""
            static std::string easy_unescape(const std::string & str);
        };
    }
}

#endif // SWARM_HTTP_CURLTOOLS_HXX
