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

#include "HTTPResponseStatus.hxx"

namespace swarm {
    namespace http {
        
        // --- 2xx ---
        
        // Define ok status
        const HTTPResponseStatus HTTPResponseStatus::OK{200, "Ok"};
        // Define ok status
        const HTTPResponseStatus HTTPResponseStatus::NO_CONTENT{204, "No Content"};
        
        // --- 4xx ---
        
        // Define not found status
        const HTTPResponseStatus HTTPResponseStatus::NOT_FOUND{404, "Not found"};

        // --- 5xx ---
        
        // Define internal server error status
        const HTTPResponseStatus HTTPResponseStatus::INTERNAL_SERVER_ERROR{500, "Internal Server Error"};
        
        // Operator ==
        bool operator==(const HTTPResponseStatus & first, const HTTPResponseStatus & second) {
            return first.code() == second.code();
        }
        
        // Satus from code
        HTTPResponseStatus HTTPResponseStatus::fromCode(int code) {
            return HTTPResponseStatus{code, "Unknown"};
        }
    }
}
