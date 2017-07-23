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

#ifndef SWARM_HTTP_DEFAULTDECODERPROVIDERFACTORY_HXX
#define SWARM_HTTP_DEFAULTDECODERPROVIDERFACTORY_HXX

#include "DecoderProviderFactory.hxx"

namespace swarm {
    namespace http {

        /// \brief Class DefaultProviderFactory
        template <class Provider> class DefaultDecoderProviderFactory : public DecoderProviderFactory {
          public:
            /// \brief Create object decoder
            /// \param stream HTTP stream
            /// \return Decoder pointer
            virtual std::shared_ptr<mapping::Decoder<mapping::ObjectDecoder>> decoder(HTTPInputStream &stream) override;
        };
    }
}

#include "DefaultDecoderProviderFactory.txx"

#endif // SWARM_HTTP_DEFAULTDECODERPROVIDERFACTORY_HXX