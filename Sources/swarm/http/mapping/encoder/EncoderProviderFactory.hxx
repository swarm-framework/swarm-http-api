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

#ifndef SWARM_HTTP_ENCODERPROVIDERFACTORY_HXX
#define SWARM_HTTP_ENCODERPROVIDERFACTORY_HXX

#include <memory>
#include <swarm/mapping/coder/Encoder.hxx>
#include <swarm/mapping/provider/ObjectProvider.hxx>

namespace swarm {
namespace http {
        
        struct HTTPOutputStream;
        
        /// \brief Class EncoderProviderFactory
        struct EncoderProviderFactory {
            
            /// \brief Create object encoder
            /// \param stream HTTP stream
            /// \return Encoder pointer
            virtual std::shared_ptr<mapping::Encoder<mapping::ObjectEncoder>> encoder(HTTPOutputStream & stream) = 0;
            
            /// \brief Destructor
            virtual ~EncoderProviderFactory() {}
        };
}}

#endif // SWARM_HTTP_ENCODERPROVIDERFACTORY_HXX
