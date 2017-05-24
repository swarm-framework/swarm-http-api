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

#include "HTTPMethod.hxx"

namespace swarm {
    namespace http {
        
        // Define GET method
        const std::shared_ptr<const HTTPMethod> HTTPMethod::GET = std::make_shared<HTTPMethod>("GET");
        
        // Define POST method
        const std::shared_ptr<const HTTPMethod> HTTPMethod::POST = std::make_shared<HTTPMethod>("POST", true);
        
        // Define PUT method
        const std::shared_ptr<const HTTPMethod> HTTPMethod::PUT = std::make_shared<HTTPMethod>("PUT", true);
        
        // Define DELETE method
        const std::shared_ptr<const HTTPMethod> HTTPMethod::DELETE = std::make_shared<HTTPMethod>("DELETE");
        
        // Define HEAD method
        const std::shared_ptr<const HTTPMethod> HTTPMethod::HEAD = std::make_shared<HTTPMethod>("HEAD");
        
        // Define OPTIONS method
        const std::shared_ptr<const HTTPMethod> HTTPMethod::OPTIONS = std::make_shared<HTTPMethod>("OPTIONS");
        
        // Define PATCH method
        const std::shared_ptr<const HTTPMethod> HTTPMethod::PATCH = std::make_shared<HTTPMethod>("PATCH");
    }
}
