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

#include "HTTPVersion.hxx"

namespace swarm {
    namespace http {
        
        // Get version bimap
        const boost::bimap<HTTPVersion, std::string> & HTTPVersions::httpVersionLabel() {
            static std::unique_ptr<boost::bimap<HTTPVersion, std::string>> map_{};
            if (!map_) {
                auto map = new boost::bimap<HTTPVersion, std::string>{};
                map->insert(boost::bimap<HTTPVersion, std::string>::value_type{HTTPVersion::HTTP10, "HTTP/1.0"});
                map->insert(boost::bimap<HTTPVersion, std::string>::value_type{HTTPVersion::HTTP11, "HTTP/1.1"});
                map->insert(boost::bimap<HTTPVersion, std::string>::value_type{HTTPVersion::HTTP20, "HTTP/2.0"});
                map_.reset(map);
            }
            return *map_;
        }
        // Get label from HTTPVersion
        std::string HTTPVersions::label(HTTPVersion version) {
            return HTTPVersions::httpVersionLabel().left.at(version);
        }

        // Get HTTPVersion from a string or throw runtime exception
        HTTPVersion HTTPVersions::get(const std::string &str) {
            return HTTPVersions::httpVersionLabel().right.at(str);
        }

        // Override ostream for HTTPVersion
        std::ostream &operator<<(std::ostream &os, HTTPVersion const &version) {
            os << HTTPVersions::label(version);
            return os;
        }
    }
}
