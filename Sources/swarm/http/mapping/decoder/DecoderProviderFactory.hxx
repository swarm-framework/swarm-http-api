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

#ifndef SWARM_HTTP_DECODERPROVIDERFACTORY_HXX
#define SWARM_HTTP_DECODERPROVIDERFACTORY_HXX

#include <memory>
#include <swarm/mapping/coder/Decoder.hxx>
#include <swarm/mapping/provider/DocumentProvider.hxx>

namespace swarm {
namespace http {

        struct HTTPInputStream;
        
        /// \brief Class DecoderProviderFactory
        struct DecoderProviderFactory {
            
            /// \brief Create object decoder
            /// \param stream HTTP stream
            /// \return Decoder pointer
            virtual std::shared_ptr<mapping::Decoder<mapping::DocumentDecoder>> decoder(HTTPInputStream & stream) = 0;
            
            /// \brief Destructor
            virtual ~DecoderProviderFactory() {}
        };
}}

#endif // SWARM_HTTP_DECODERPROVIDERFACTORY_HXX
