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
            
            /// \brief Test operator
            /// \param other Other response status
            /// \return True if code are same
            bool operator==(const HTTPResponseStatus & other) {
                return other.code_ == this->code_;;
            }
            
        public:
            
            // --- 2XX --
            
            /// \brief OK status (200)
            static const HTTPResponseStatus OK;
            
            /// \brief No Content status (204)
            static const HTTPResponseStatus NO_CONTENT;

            // --- 4XX --

            /// \brief Not found status
            static const HTTPResponseStatus NOT_FOUND;

            // --- 5XX --

            /// \brief Internal server error status
            static const HTTPResponseStatus INTERNAL_SERVER_ERROR;
            
        public:
            
            /// \brief Satus from code
            /// \param code Status code
            /// \return HTTPResponseStatus
            static HTTPResponseStatus fromCode(int code);
        };
        
        /// \brief Test operator between first and second
        /// \param first First response status
        /// \param second Second response status
        /// \return True if code are same
        bool operator==(const HTTPResponseStatus & first, const HTTPResponseStatus & second);
    }
}

#endif // SWARM_HTTP_HTTPRESPONSESTATUS_HXX
