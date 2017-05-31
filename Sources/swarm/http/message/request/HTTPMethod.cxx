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

        // Operator egual
        HTTPMethod & HTTPMethod::operator=(const HTTPMethod & method) {
                this->name_ = method.name_;
                this->bodyAllowed_ = method.bodyAllowed_;

                return *this;
        }

        // Define GET method
        const HTTPMethod HTTPMethod::GET{"GET"};
        
        // Define POST method
        const HTTPMethod HTTPMethod::POST{"POST", true};
        
        // Define PUT method
        const HTTPMethod HTTPMethod::PUT{"PUT", true};
        
        // Define DELETE method
        const HTTPMethod HTTPMethod::DELETE{"DELETE"};
        
        // Define HEAD method
        const HTTPMethod HTTPMethod::HEAD{"HEAD"};
        
        // Define OPTIONS method
        const HTTPMethod HTTPMethod::OPTIONS{"OPTIONS"};
        
        // Define PATCH method
        const HTTPMethod HTTPMethod::PATCH{"PATCH"};
    }
}
