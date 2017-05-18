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

#include "CURLTools.hxx"

#include <cxxlog/Level.hxx>

namespace swarm {
    namespace http {
        
        // Init curl easy
        CURL *CURLTools::curl_ = curl_easy_init();
        
        // Init logger
        cxxlog::Logger CURLTools::LOGGER_ = LOGGER(CURLTools);
        
        // Escape a string
        std::string CURLTools::easy_escape(const std::string & str) {
            if (str.empty()) {
                CURLTools::LOGGER_.log(cxxlog::Level::FINE, "Unable to encode empty string");
                return str;
            }
            
            // Convert char *
            char * converted = curl_easy_escape(CURLTools::curl_, str.c_str(), str.size());
            if (converted) {
                std::string result{converted};
                curl_free(converted);
                return std::move(result);
            } else {
                CURLTools::LOGGER_.log(cxxlog::Level::FINE, "Unable to encode '%1%'", str);
                return str;
            }
            
            return std::string{};
        }
        
        // Unescape string
        std::string CURLTools::easy_unescape(const std::string & str) {
            
            if (str.empty()) {
                CURLTools::LOGGER_.log(cxxlog::Level::FINE, "Unable to decode empty string");
                return str;
            }
            
            int outlength = 0;
            char * decoded = curl_easy_unescape(CURLTools::curl_, str.c_str(), str.size(), &outlength);
            if (decoded) {
                std::string result{decoded};
                curl_free(decoded);
                return std::move(result);
            } else {
                CURLTools::LOGGER_.log(cxxlog::Level::FINE, "Unable to decode '%1%'", str);
                return std::string{};
            }
        }
    }
}
