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

#include "URIEncoding.hxx"

#include "CURLTools.hxx"

namespace swarm {
    namespace http {
        
        // URL encode a string
        std::string URIEncoding::encode(const std::string & str) {
            return CURLTools::easy_escape(str);
        }
        
        // URL decode a string
        std::string URIEncoding::decode(const std::string & str) {
            return CURLTools::easy_unescape(str);
        }
    }
}