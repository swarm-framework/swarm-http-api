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
#include <catch/catch.hxx>

#include <swarm/http/message/response/HTTPResponse.hxx>
#include <swarm/http/message/response/HTTPResponseBuilder.hxx>

using namespace swarm::http;

TEST_CASE("HTTP response", "[HTTPMessage]") {
    
    // Create http builder
    HTTPResponseBuilder httpResponseBuilder{};
    auto response = httpResponseBuilder.build();
    REQUIRE(true);
}
