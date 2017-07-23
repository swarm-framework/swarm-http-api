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

#ifndef SWARM_HTTP_PROVIDERREGISTRY_HXX
#define SWARM_HTTP_PROVIDERREGISTRY_HXX

#include <map>
#include <memory>
#include <string>

namespace swarm {
    namespace http {

        class MediaType;
        class HTTPBody;
        class EncoderProviderFactory;
        class DecoderProviderFactory;

        /// \brief Class ProviderRegistry
        class ProviderRegistry {

          private:
            /// \brief Encoder provider factories
            std::map<std::string, std::shared_ptr<EncoderProviderFactory>> encoderProviderFactories_;

            /// \brief Decoder provider factories
            std::map<std::string, std::shared_ptr<DecoderProviderFactory>> decoderProviderFactories_;

          public:
            /// \brief Constructor
            ProviderRegistry();

            /// \return Default registry
            static ProviderRegistry &defaultRegistry();

            /// \brief Register encoder provider for a media type
            /// \param mediaType Media-type to register
            /// \param factory Provider factory associated as media type
            void registerEncoderProvider(const MediaType &mediaType, std::shared_ptr<EncoderProviderFactory> factory);

            /// \brief Register decoder provider for a media type
            /// \param mediaType Media-type to register
            /// \param factory Provider factory associated as media type
            void registerDecoderProvider(const MediaType &mediaType, std::shared_ptr<DecoderProviderFactory> factory);

            /// \return Get encoder provider
            std::shared_ptr<EncoderProviderFactory> getEncoder(const MediaType &mediaType);

            /// \return Get decoder provider
            std::shared_ptr<DecoderProviderFactory> getDecoder(const MediaType &mediaType);
        };
    }
}

#endif // SWARM_HTTP_PROVIDERREGISTRY_HXX
