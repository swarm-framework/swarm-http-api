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

#include "HTTPHeaders.hxx"

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
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCESS_CONTROL_ALLOW_ORIGIN = HTTPHeaders::get("Access-Control-Allow-Origin");
        
        // Accept language header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT = HTTPHeaders::get("Accept");
        
        // Accept charset header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_CHARSET = HTTPHeaders::get("Accept-Charset");
        
        // Accept encoding header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_ENCODING = HTTPHeaders::get("Accept-Encoding");
        
        // Accept language header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_LANGUAGE = HTTPHeaders::get("Accept-Language");
        
        // Accept encoding header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_DATETIME = HTTPHeaders::get("Accept-Datetime");
        
        // Authorization header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ACCEPT_AUTHORIZATION = HTTPHeaders::get("Authorization");
        
        // Age in cache header
        std::shared_ptr<const HTTPHeader> HTTPHeader::AGE = HTTPHeaders::get("Age");
        
        // Allow header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ALLOW = HTTPHeaders::get("Allow");
        
        // Cache control header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CACHE_CONTROL = HTTPHeaders::get("Cache-Control");
        
        // Connection header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONNECTION = HTTPHeaders::get("Connection");
        
        // Cookie
        std::shared_ptr<const HTTPHeader> HTTPHeader::COOKIE = HTTPHeaders::get("Cookie");
        
        // Content disposition header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_DISPOSITION = HTTPHeaders::get("Content-Disposition");
        
        // Content type length
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_LENGTH = HTTPHeaders::get("Content-Length");
        
        // Content MD5 header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_LOCATION = HTTPHeaders::get("Content-Location");
        
        // Content MD5 header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_MD5 = HTTPHeaders::get("Content-MD5");
        
        // Content range header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_RANGE = HTTPHeaders::get("Content-Range");
        
        // ContentType header
        std::shared_ptr<const HTTPHeader> HTTPHeader::CONTENT_TYPE = HTTPHeaders::get("Content-Type");
        
        // Date header
        std::shared_ptr<const HTTPHeader> HTTPHeader::DATE = HTTPHeaders::get("Date");
        
        // Etag header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ETAG = HTTPHeaders::get("ETag");
        
        // Expires header
        std::shared_ptr<const HTTPHeader> HTTPHeader::EXPIRES = HTTPHeaders::get("Expires");
        
        // Host header
        std::shared_ptr<const HTTPHeader> HTTPHeader::HOST = HTTPHeaders::get("Host");
        
        // Last-Modified header
        std::shared_ptr<const HTTPHeader> HTTPHeader::LAST_MODIFIED = HTTPHeaders::get("Last-Modified");
        
        // Link header
        std::shared_ptr<const HTTPHeader> HTTPHeader::LINK = HTTPHeaders::get("Link");
        
        // Location header
        std::shared_ptr<const HTTPHeader> HTTPHeader::LOCATION = HTTPHeaders::get("Location");
        
        // Origin header
        std::shared_ptr<const HTTPHeader> HTTPHeader::ORIGIN = HTTPHeaders::get("Origin");
        
        // Proxy-Authorization header
        std::shared_ptr<const HTTPHeader> HTTPHeader::PROXY_AUTHORIZATION = HTTPHeaders::get("Proxy-Authorization");
        
        // Proxy-Authenticate header
        std::shared_ptr<const HTTPHeader> HTTPHeader::PROXY_AUTHENTICATE = HTTPHeaders::get("Proxy-Authenticate");
        
        // Range header
        std::shared_ptr<const HTTPHeader> HTTPHeader::RANGE = HTTPHeaders::get("Range");
        
        // Refresh header
        std::shared_ptr<const HTTPHeader> HTTPHeader::REFRESH = HTTPHeaders::get("Refresh");
        
        // Retry after header
        std::shared_ptr<const HTTPHeader> HTTPHeader::RETRY_AFTER = HTTPHeaders::get("Retry-After");
        
        // Server header
        std::shared_ptr<const HTTPHeader> HTTPHeader::SERVER = HTTPHeaders::get("Server");
        
        // Set-cookie header
        std::shared_ptr<const HTTPHeader> HTTPHeader::SET_COOKIE = HTTPHeaders::get("Set-Cookie");
        
        // Transfert encoding header
        std::shared_ptr<const HTTPHeader> HTTPHeader::TRANSFERT_ENCODING = HTTPHeaders::get("Transfer-Encoding");
        
        // User agent header
        std::shared_ptr<const HTTPHeader> HTTPHeader::USER_AGENT = HTTPHeaders::get("User-Agent");
        
        // Proxy-Authorization header
        std::shared_ptr<const HTTPHeader> HTTPHeader::VIA = HTTPHeaders::get("Via");
        
        // WWW-Authenticat header
        std::shared_ptr<const HTTPHeader> HTTPHeader::WWW_AUTHENTICATE = HTTPHeaders::get("WWW-Authenticate");
        
        // X-Powered-By header
        std::shared_ptr<const HTTPHeader> HTTPHeader::X_POWERED_BY = HTTPHeaders::get("X-Powered-By");
        
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
