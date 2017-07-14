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

#ifndef SWARM_HTTP_HTTPHEADER_HXX
#define SWARM_HTTP_HTTPHEADER_HXX

#include <string>
#include <memory>

namespace swarm {
    namespace http {

        /// \brief Class HTTPHeader
        class HTTPHeader {
        private:
            
            /// \brief Header key
            std::string key_;
            
        public:
            
            /// \brief COnstructor with key
            /// \param key Header key
            HTTPHeader(const std::string & key);
            
            /// \brief Get header key
            /// \return String containing header key
            const std::string & key() const {
                return key_;
            }
            
            /// \brief define less operator using key less
            bool operator<(const HTTPHeader & other) const;
            
        public:
            
            /// \brief Access-Control-Allow-Origin header
            static std::shared_ptr<const HTTPHeader> ACCESS_CONTROL_ALLOW_ORIGIN;
            
            /// \brief Accept language header
            static std::shared_ptr<const HTTPHeader> ACCEPT;
            
            /// \brief Accept charset header
            static std::shared_ptr<const HTTPHeader> ACCEPT_CHARSET;
            
            /// \brief Accept encoding header
            static std::shared_ptr<const HTTPHeader> ACCEPT_ENCODING;
            
            /// \brief Accept language header
            static std::shared_ptr<const HTTPHeader> ACCEPT_LANGUAGE;
            
            /// \brief Accept Datetime header
            static std::shared_ptr<const HTTPHeader> ACCEPT_DATETIME;
            
            /// \brief Authorization header
            static std::shared_ptr<const HTTPHeader> ACCEPT_AUTHORIZATION;
            
            /// \brief Age in cache header
            static std::shared_ptr<const HTTPHeader> AGE;
            
            /// \brief Allow header
            static std::shared_ptr<const HTTPHeader> ALLOW;
            
            /// \brief Cache control header
            static std::shared_ptr<const HTTPHeader> CACHE_CONTROL;
            
            /// \brief Connection header
            static std::shared_ptr<const HTTPHeader> CONNECTION;
            
            /// \brief Cookie
            static std::shared_ptr<const HTTPHeader> COOKIE;
            
            /// \brief Content disposition header
            static std::shared_ptr<const HTTPHeader> CONTENT_DISPOSITION;
            
            /// \brief Content type length
            static std::shared_ptr<const HTTPHeader> CONTENT_LENGTH;
            
            /// \brief Content location header
            static std::shared_ptr<const HTTPHeader> CONTENT_LOCATION;
            
            /// \brief Content MD5 header
            static std::shared_ptr<const HTTPHeader> CONTENT_MD5;
            
            /// \brief Content range header
            static std::shared_ptr<const HTTPHeader> CONTENT_RANGE;
            
            /// \brief ContentType header
            static std::shared_ptr<const HTTPHeader> CONTENT_TYPE;
            
            /// \brief Date header
            static std::shared_ptr<const HTTPHeader> DATE;
            
            /// \brief Etag header
            static std::shared_ptr<const HTTPHeader> ETAG;
            
            /// \brief Expires header
            static std::shared_ptr<const HTTPHeader> EXPIRES;
            
            /// \brief Host header
            static std::shared_ptr<const HTTPHeader> HOST;
            
            /// \brief Last-Modified header
            static std::shared_ptr<const HTTPHeader> LAST_MODIFIED;
            
            /// \brief Link header
            static std::shared_ptr<const HTTPHeader> LINK;
            
            /// \brief Location header
            static std::shared_ptr<const HTTPHeader> LOCATION;
            
            /// \brief Origin header
            static std::shared_ptr<const HTTPHeader> ORIGIN;
            
            /// \brief Proxy-Authorization header
            static std::shared_ptr<const HTTPHeader> PROXY_AUTHORIZATION;
            
            /// \brief Proxy-Authenticate header
            static std::shared_ptr<const HTTPHeader> PROXY_AUTHENTICATE;
            
            /// \brief Range header
            static std::shared_ptr<const HTTPHeader> RANGE;
            
            /// \brief Refresh header
            static std::shared_ptr<const HTTPHeader> REFRESH;
            
            /// \brief Retry-after header
            static std::shared_ptr<const HTTPHeader> RETRY_AFTER;
            
            /// \brief Server header
            static std::shared_ptr<const HTTPHeader> SERVER;
            
            /// \brief Set-cookie header
            static std::shared_ptr<const HTTPHeader> SET_COOKIE;
            
            /// \bief Transfert encoding header
            static std::shared_ptr<const HTTPHeader> TRANSFERT_ENCODING;
            
            /// \brief User agent header
            static std::shared_ptr<const HTTPHeader> USER_AGENT;
            
            /// \brief Via header
            static std::shared_ptr<const HTTPHeader> VIA;
            
            /// \brief WWW-Authenticate header
            static std::shared_ptr<const HTTPHeader> WWW_AUTHENTICATE;
            
            /// \brief X-Powered-By header
            static std::shared_ptr<const HTTPHeader> X_POWERED_BY;
        };
        
        // Override ostream
        std::ostream & operator<<(std::ostream & os, const HTTPHeader & header);
        std::ostream & operator<<(std::ostream & os, std::shared_ptr<const HTTPHeader> header);
    }
}

#endif // SWARM_HTTP_HTTPHEADER_HXX
