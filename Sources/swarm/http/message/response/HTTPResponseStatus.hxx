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

#ifndef SWARM_HTTP_HTTPRESPONSESTATUS_HXX
#define SWARM_HTTP_HTTPRESPONSESTATUS_HXX

#include <string>

namespace swarm {
    namespace http {
        
        /// \brief Define HTTP response status
        class HTTPResponseStatus {
            
        private:
            
            /// \brief HTTP code
            int code_;
            
            /// \brief HTTP reason
            std::string reason_;
            
        protected:
            
            /// \brief Constructor with code and reason
            /// \param code HTTP code
            /// \param reason HTTP reason
            HTTPResponseStatus(int code, const std::string & reason) : code_(code), reason_(reason) {
                
            }
            
        public:
            /// \brief Copy constructor
            /// \param status other status
            HTTPResponseStatus(const HTTPResponseStatus & status) : code_(status.code_), reason_(status.reason_) {
                
            }
            
        public:
            
            /// \return HTTP code
            int code() const {
                return code_;
            }
            
            /// \return HTTP reason
            const std::string & reason() const {
                return reason_;
            }
            
        public:
            
            // --- 2XX --
            
            /// \brief OK status
            static const HTTPResponseStatus OK;
            
            // --- 4XX --
            
            /// \brief Not found status
            static const HTTPResponseStatus NOT_FOUND;
        };
    }
}

#endif // SWARM_HTTP_HTTPRESPONSESTATUS_HXX
