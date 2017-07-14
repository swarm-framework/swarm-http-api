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

#include "HTTPHeader.hxx"

namespace swarm {
    namespace http {
        
        // Constructor with key
        HTTPHeader::HTTPHeader(const std::string & key) : key_(key) {
            
        }
        
        /// \brief define less operator using key less
        bool HTTPHeader::operator<(const HTTPHeader & other) const {
            return key_ < other.key();
        }
        
        // Access-Control-Allow-Origin header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCESS_CONTROL_ALLOW_ORIGIN = std::make_shared<HTTPHeader>("Access-Control-Allow-Origin");
        
        // Accept language header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT = std::make_shared<HTTPHeader>("Accept");
        
        // Accept charset header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_CHARSET = std::make_shared<HTTPHeader>("Accept-Charset");
        
        // Accept encoding header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_ENCODING = std::make_shared<HTTPHeader>("Accept-Encoding");
        
        // Accept language header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_LANGUAGE = std::make_shared<HTTPHeader>("Accept-Language");
        
        // Accept encoding header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_DATETIME = std::make_shared<HTTPHeader>("Accept-Datetime");
        
        // Authorization header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_AUTHORIZATION = std::make_shared<HTTPHeader>("Authorization");
        
        // Age in cache header
        std::shared_ptr<const HTTPHeader> HTTPHeader::AGE = std::make_shared<HTTPHeader>("Age");
        
        // Allow header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ALLOW = std::make_shared<HTTPHeader>("Allow");
        
        // Cache control header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CACHE_CONTROL = std::make_shared<HTTPHeader>("Cache-Control");
        
        // Connection header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONNECTION = std::make_shared<HTTPHeader>("Connection");
        
        // Cookie
        std::shared_ptr<const HTTPHeader> HTTPHeader::COOKIE = std::make_shared<HTTPHeader>("Cookie");
        
        // Content disposition header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_DISPOSITION = std::make_shared<HTTPHeader>("Content-Disposition");
        
        // Content type length
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_LENGTH = std::make_shared<HTTPHeader>("Content-Length");
        
        // Content MD5 header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_LOCATION = std::make_shared<HTTPHeader>("Content-Location");
        
        // Content MD5 header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_MD5 = std::make_shared<HTTPHeader>("Content-MD5");
        
        // Content range header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_RANGE = std::make_shared<HTTPHeader>("Content-Range");
        
        // ContentType header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_TYPE = std::make_shared<HTTPHeader>("Content-Type");
        
        // Date header
        std::shared_ptr<const HTTPHeader> HTTPHeader::DATE = std::make_shared<HTTPHeader>("Date");
        
        // Etag header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ETAG = std::make_shared<HTTPHeader>("ETag");
        
        // Expires header
        std::shared_ptr<const HTTPHeader> HTTPHeader::EXPIRES = std::make_shared<HTTPHeader>("Expires");
        
        // Host header
        std::shared_ptr<const HTTPHeader> HTTPHeader::HOST = std::make_shared<HTTPHeader>("Host");
        
        // Last-Modified header
        std::shared_ptr<const HTTPHeader> HTTPHeader::LAST_MODIFIED = std::make_shared<HTTPHeader>("Last-Modified");
        
        // Link header
        std::shared_ptr<const HTTPHeader> HTTPHeader::LINK = std::make_shared<HTTPHeader>("Link");
        
        // Location header
        std::shared_ptr<const HTTPHeader> HTTPHeader::LOCATION = std::make_shared<HTTPHeader>("Location");
        
        // Origin header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ORIGIN = std::make_shared<HTTPHeader>("Origin");
        
        // Proxy-Authorization header
        std::shared_ptr<const HTTPHeader> HTTPHeader::PROXY_AUTHORIZATION = std::make_shared<HTTPHeader>("Proxy-Authorization");
        
        // Proxy-Authenticate header
        std::shared_ptr<const HTTPHeader> HTTPHeader::PROXY_AUTHENTICATE = std::make_shared<HTTPHeader>("Proxy-Authenticate");
        
        // Range header
        std::shared_ptr<const HTTPHeader> HTTPHeader::RANGE = std::make_shared<HTTPHeader>("Range");
        
        // Refresh header
        std::shared_ptr<const HTTPHeader> HTTPHeader::REFRESH = std::make_shared<HTTPHeader>("Refresh");
        
        // Retry after header
        std::shared_ptr<const HTTPHeader> HTTPHeader::RETRY_AFTER = std::make_shared<HTTPHeader>("Retry-After");
        
        // Server header
        std::shared_ptr<const HTTPHeader> HTTPHeader::SERVER = std::make_shared<HTTPHeader>("Server");
        
        // Set-cookie header
        std::shared_ptr<const HTTPHeader> HTTPHeader::SET_COOKIE = std::make_shared<HTTPHeader>("Set-Cookie");
        
        // Transfert encoding header
        std::shared_ptr<const HTTPHeader> HTTPHeader::TRANSFERT_ENCODING = std::make_shared<HTTPHeader>("Transfer-Encoding");
        
        // User agent header
        std::shared_ptr<const HTTPHeader> HTTPHeader::USER_AGENT = std::make_shared<HTTPHeader>("User-Agent");
        
        // Proxy-Authorization header
        std::shared_ptr<const HTTPHeader> HTTPHeader::VIA = std::make_shared<HTTPHeader>("Via");
        
        // WWW-Authenticat header
        std::shared_ptr<const HTTPHeader> HTTPHeader::WWW_AUTHENTICATE = std::make_shared<HTTPHeader>("WWW-Authenticate");
        
        // X-Powered-By header
        std::shared_ptr<const HTTPHeader> HTTPHeader::X_POWERED_BY = std::make_shared<HTTPHeader>("X-Powered-By");
        
        // Override ostream
        std::ostream & operator<<(std::ostream & os, const HTTPHeader & header) {
            os << header.key();
            return os;
        }
                
        // Override ostream
        std::ostream & operator<<(std::ostream & os, std::shared_ptr<const HTTPHeader> header) {
            if (header) {
                os << header->key();
            }
            return os;
        }
    }
}
