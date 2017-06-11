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

#include "HTTPParam.hxx"

#include "../../tools/URIEncoding.hxx"

namespace swarm {
    namespace http {
        
        // Create an HTTP parameter from non encoded value
        std::shared_ptr<HTTPParam> HTTPParam::fromValue(const std::string & key, const std::string & value) {
            return std::make_shared<HTTPOutputParam>(key, value);
        }
        
        // Create an HTTP parameter from encoded value
        std::shared_ptr<HTTPParam> HTTPParam::fromEncodedValue(const std::string & key, const std::string & encodedValue) {
            return std::make_shared<HTTPInputParam>(key, encodedValue);
        }
        
        // --- HTTPInputParam ---
        
        // Constructor with values
        HTTPInputParam::HTTPInputParam(const std::string & key, const std::string & value) : key_(key), rawValue_(value) {
            
        }
        
        // Get param key
        const std::string &HTTPInputParam::key() const { return key_; }
        
        // Get raw param value
        const std::string &HTTPInputParam::rawValue() const { return rawValue_; }
        
        // Get decoded value
        const std::string &HTTPInputParam::value() const {
            if (!value_) {
                value_.reset(new std::string{URIEncoding::decode(rawValue_)});
            }
            return *value_;
        }
        
        // --- HTTPOutputParam ---
        
        // Constructor with values
        HTTPOutputParam::HTTPOutputParam(const std::string & key, const std::string & value) : key_(key), rawValue_(value) {
            
        }
        
        // Get param key
        const std::string &HTTPOutputParam::key() const { return key_; }
        
        // Get raw param value
        const std::string &HTTPOutputParam::rawValue() const { return rawValue_; }
        
        // Get encoded value
        const std::string &HTTPOutputParam::value() const {
            if (!value_) {
                value_.reset(new std::string{URIEncoding::encode(rawValue_)});
            }
            return *value_;
        }
    }
}
