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
        const HTTPHeader HTTPHeader::ACCESS_CONTROL_ALLOW_ORIGIN = HTTPHeader{"Access-Control-Allow-Origin"};
        
        // Accept language header
        const HTTPHeader HTTPHeader::ACCEPT = HTTPHeader{"Accept"};
        
        // Accept charset header
        const HTTPHeader HTTPHeader::ACCEPT_CHARSET = HTTPHeader{"Accept-Charset"};
        
        // Accept encoding header
        const HTTPHeader HTTPHeader::ACCEPT_ENCODING = HTTPHeader{"Accept-Encoding"};
        
        // Accept language header
        const HTTPHeader HTTPHeader::ACCEPT_LANGUAGE = HTTPHeader{"Accept-Language"};
        
        // Accept encoding header
        const HTTPHeader HTTPHeader::ACCEPT_DATETIME = HTTPHeader{"Accept-Datetime"};
        
        // Authorization header
        const HTTPHeader HTTPHeader::ACCEPT_AUTHORIZATION = HTTPHeader{"Authorization"};
        
        // Age in cache header
        const HTTPHeader HTTPHeader::AGE = HTTPHeader{"Age"};
        
        // Allow header
        const HTTPHeader HTTPHeader::ALLOW = HTTPHeader{"Allow"};
        
        // Cache control header
        const HTTPHeader HTTPHeader::CACHE_CONTROL = HTTPHeader{"Cache-Control"};
        
        // Connection header
        const HTTPHeader HTTPHeader::CONNECTION = HTTPHeader{"Connection"};
        
        // Cookie
        const HTTPHeader HTTPHeader::COOKIE = HTTPHeader{"Cookie"};
        
        // Content disposition header
        const HTTPHeader HTTPHeader::CONTENT_DISPOSITION = HTTPHeader{"Content-Disposition"};
        
        // Content type length
        const HTTPHeader HTTPHeader::CONTENT_LENGTH = HTTPHeader{"Content-Length"};
        
        // Content MD5 header
        const HTTPHeader HTTPHeader::CONTENT_LOCATION = HTTPHeader{"Content-Location"};
        
        // Content MD5 header
        const HTTPHeader HTTPHeader::CONTENT_MD5 = HTTPHeader{"Content-MD5"};
        
        // Content range header
        const HTTPHeader HTTPHeader::CONTENT_RANGE = HTTPHeader{"Content-Range"};
        
        // ContentType header
        const HTTPHeader HTTPHeader::CONTENT_TYPE = HTTPHeader{"Content-Type"};
        
        // Date header
        const HTTPHeader HTTPHeader::DATE = HTTPHeader{"Date"};
        
        // Etag header
        const HTTPHeader HTTPHeader::ETAG = HTTPHeader{"ETag"};
        
        // Expires header
        const HTTPHeader HTTPHeader::EXPIRES = HTTPHeader{"Expires"};
        
        // Host header
        const HTTPHeader HTTPHeader::HOST = HTTPHeader{"Host"};
        
        // Last-Modified header
        const HTTPHeader HTTPHeader::LAST_MODIFIED = HTTPHeader{"Last-Modified"};
        
        // Link header
        const HTTPHeader HTTPHeader::LINK = HTTPHeader{"Link"};
        
        // Location header
        const HTTPHeader HTTPHeader::LOCATION = HTTPHeader{"Location"};
        
        // Origin header
        const HTTPHeader HTTPHeader::ORIGIN = HTTPHeader{"Origin"};
        
        // Proxy-Authorization header
        const HTTPHeader HTTPHeader::PROXY_AUTHORIZATION = HTTPHeader{"Proxy-Authorization"};
        
        // Proxy-Authenticate header
        const HTTPHeader HTTPHeader::PROXY_AUTHENTICATE = HTTPHeader{"Proxy-Authenticate"};
        
        // Range header
        const HTTPHeader HTTPHeader::RANGE = HTTPHeader{"Range"};
        
        // Refresh header
        const HTTPHeader HTTPHeader::REFRESH = HTTPHeader{"Refresh"};
        
        // Retry after header
        const HTTPHeader HTTPHeader::RETRY_AFTER = HTTPHeader{"Retry-After"};
        
        // Server header
        const HTTPHeader HTTPHeader::SERVER = HTTPHeader{"Server"};
        
        // Set-cookie header
        const HTTPHeader HTTPHeader::SET_COOKIE = HTTPHeader{"Set-Cookie"};
        
        // Transfert encoding header
        const HTTPHeader HTTPHeader::TRANSFERT_ENCODING = HTTPHeader{"Transfer-Encoding"};
        
        // User agent header
        const HTTPHeader HTTPHeader::USER_AGENT = HTTPHeader{"User-Agent"};
        
        // Proxy-Authorization header
        const HTTPHeader HTTPHeader::VIA = HTTPHeader{"Via"};
        
        // WWW-Authenticat header
        const HTTPHeader HTTPHeader::WWW_AUTHENTICATE = HTTPHeader{"WWW-Authenticate"};
        
        // X-Powered-By header
        const HTTPHeader HTTPHeader::X_POWERED_BY = HTTPHeader{"X-Powered-By"};
    }
}
