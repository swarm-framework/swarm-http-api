/*
 * Copyright 2017 dami <email>
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

#include <swarm/mapping/provider/rapidjson/RapidJSONEncoder.hxx>
#include <swarm/mapping/provider/rapidjson/RapidJSONDecoder.hxx>
#include <swarm/http/mapping/encoder/DefaultEncoderProviderFactory.hxx>
#include <swarm/http/mapping/decoder/DefaultDecoderProviderFactory.hxx>
#include <swarm/http/stream/input/DefaultHTTPInputStream.hxx>
#include <swarm/http/stream/output/DefaultHTTPOutputStream.hxx>

using namespace swarm::http;
using namespace swarm::mapping;

TEST_CASE("HTTP body mapping", "[Mapping]") {
    
    std::stringstream ssInput;
    std::stringstream ssOutput;
    
    DefaultHTTPOutputStream outputStream{ssOutput};
    
    DefaultEncoderProviderFactory<RapidJSONEncoder> encoderFactory{};
    auto object = encoderFactory.encoder(outputStream);
    
    DefaultHTTPInputStream inputStream{ssInput};
    
    DefaultDecoderProviderFactory<RapidJSONDecoder> decoderFactory{};
    auto ostream = decoderFactory.decoder(inputStream);
}
