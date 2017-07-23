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

#ifndef SWARM_HTTP_DEFAULTENCODERPROVIDERFACTORY_HXX
#define SWARM_HTTP_DEFAULTENCODERPROVIDERFACTORY_HXX

#include "EncoderProviderFactory.hxx"

namespace swarm {
    namespace http {

        /// \brief Class DefaultProviderFactory
        template <class Provider> class DefaultEncoderProviderFactory : public EncoderProviderFactory {
          public:
              
            /// \brief Create object encoder
            /// \param stream HTTP stream
            /// \return Encoder pointer
            virtual std::shared_ptr<mapping::Encoder<mapping::DocumentEncoder>>
            encoder(HTTPOutputStream &stream) override;
        };
    }
}

#include "DefaultEncoderProviderFactory.txx"

#endif // SWARM_HTTP_DEFAULTENCODERPROVIDERFACTORY_HXX
