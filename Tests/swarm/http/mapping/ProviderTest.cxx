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
#include <swarm/mapping/coder/Encoder.hxx>
#include <swarm/http/mapping/encoder/DefaultEncoderProviderFactory.hxx>
#include <swarm/http/mapping/decoder/DefaultDecoderProviderFactory.hxx>
#include <swarm/http/stream/input/DefaultHTTPInputStream.hxx>
#include <swarm/http/stream/output/DefaultHTTPOutputStream.hxx>
#include <swarm/mapping/provider/DocumentProvider.hxx>

using namespace swarm::http;
using namespace swarm::mapping;

namespace test {
 
    class Object1 {
    public:
        int attr = 2;
    };
    
    bool operator==(const Object1 & first, const Object1 & second) {
        return first.attr == second.attr;
    }
}

namespace swarm {

    namespace mapping {
        
        using namespace test;
        
        template<class EncoderProvider, class DecoderProvider>
        struct Mapping<EncoderProvider, DecoderProvider, Object1> : public DefaultMapping<EncoderProvider, DecoderProvider, Object1> {
            
            /// \brief Encode an object
            /// \param encoder Encoder provider
            /// \param o Object to encode
            virtual void encode(Encoder<EncoderProvider> & encoder, const Object1 & o) override {
                //encoder.template encodeAttribute("attr", o.attr);
            }

            /// \brief Decode an object
            /// \param decoder Decoder provider
            virtual std::shared_ptr<Object1> decode(Decoder<DecoderProvider> &decoder) override {
                auto object = std::make_shared<Object1>();
                return object;
            }

            virtual ~Mapping() {}
        };
    }
            
}

TEST_CASE("HTTP body mapping", "[Mapping]") {
    
    std::stringstream ssInput;
    std::stringstream ssOutput;
    
    // Create mapping
    swarm::mapping::Mapping<DocumentEncoder, DocumentDecoder, Object1> mapping{};
    
    // Create output stream
    DefaultHTTPOutputStream outputStream{ssOutput};
    
    // Create factory
    DefaultEncoderProviderFactory<RapidJSONEncoder> encoderFactory{};
    
    // Create encoder from outputStream
    auto encoder = encoderFactory.encoder(outputStream);
    
    // Create object
    Object1 objectToEncode{};
    objectToEncode.attr = 42;
    
    // Encode object
    mapping.encode(*encoder, objectToEncode);
    
    // Create input stream
    DefaultHTTPInputStream inputStream{ssInput};
    
    // Create decoder factory
    DefaultDecoderProviderFactory<RapidJSONDecoder> decoderFactory{};
    
    // Create decoder from inputstream
    std::shared_ptr<swarm::mapping::Decoder<swarm::mapping::DocumentDecoder>> decoder = decoderFactory.decoder(inputStream);
    
    // Encode object
    auto decodedObject = mapping.decode(*decoder);
    
    REQUIRE(decodedObject);
    REQUIRE(objectToEncode == *decodedObject);
    //REQUIRE(decodedObject->attr == 42);
}
