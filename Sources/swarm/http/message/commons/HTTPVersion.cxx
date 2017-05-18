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

#include <boost/bimap.hpp>

using namespace swarm::http;

namespace HTTPVersions_private {
    // Define all versions couples
    static const boost::bimap<HTTPVersion, std::string> httpVersionLabel{};
}

// Get label from HTTPVersion
std::string HTTPVersions::label(HTTPVersion version) { return HTTPVersions_private::httpVersionLabel.left.at(version); }

// Get HTTPVersion from a string or throw runtime exception
HTTPVersion HTTPVersions::get(const std::string &str) { return HTTPVersions_private::httpVersionLabel.right.at(str); }

// Override ostream for HTTPVersion
std::ostream &operator<<(std::ostream &os, const HTTPVersion &version) {
    os << HTTPVersions::label(version);
    return os;
}
