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

#ifndef SWARM_HTTP_HTTPMETHOD_HXX
#define SWARM_HTTP_HTTPMETHOD_HXX

#include <memory>
#include <string>

namespace swarm {
    namespace http {

        /// \brief Define HTTP method
        class HTTPMethod {
            
        private:
            
            /// \brief Method name
            std::string name_;
                        
            /// \brief May have body.
            bool bodyAllowed_;
            
        public:
            
            /// \brief Constructor with name and optionally body
            /// \param name Method name
            /// \param body All body usage (false by default)
            HTTPMethod(const std::string & name, bool body = false) : name_(name), bodyAllowed_(body) {
                
            }
            
            /// \brief Copy constructor
            /// \param method other method
            HTTPMethod(const HTTPMethod & method) : name_(method.name_), bodyAllowed_(method.bodyAllowed_) {
                
            } 
            
            /// \brief Move constructor
            /// \param method other method
            HTTPMethod(HTTPMethod && method) : name_(std::move(method.name_)), bodyAllowed_(method.bodyAllowed_) {
                
            } 
            
            /// \brief Retirve the method name
            /// \return String containing the method name
            const std::string & name() const {
                return name_;
            }
            
            /// \brief Test if method can have body
            /// \return true if method can have a body false in other cases
            bool bodyAllowed() const {
                return bodyAllowed_;
            }
            
        public:
            
            /// \breif Define GET method
            static const std::shared_ptr<const HTTPMethod> GET;
            
            /// \breif Define POST method
            static const std::shared_ptr<const HTTPMethod> POST;
            
            /// \breif Define PUT method
            static const std::shared_ptr<const HTTPMethod> PUT;
            
            /// \breif Define DELETE method
            static const std::shared_ptr<const HTTPMethod> DELETE;
            
            /// \breif Define HEAD method
            static const std::shared_ptr<const HTTPMethod> HEAD;
            
            /// \breif Define OPTIONS method
            static const std::shared_ptr<const HTTPMethod> OPTIONS;
            
            /// \breif Define PATCH method
            static const std::shared_ptr<const HTTPMethod> PATCH;
        };
    }
}

#endif // SWARM_HTTP_HTTPMETHOD_HXX
