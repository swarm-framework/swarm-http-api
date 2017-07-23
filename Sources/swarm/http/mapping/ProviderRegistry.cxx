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

#include "ProviderRegistry.hxx"

#include <swarm/http/MediaType.hxx>

namespace swarm {
    namespace http {

        // Constructor
        ProviderRegistry::ProviderRegistry() {}

        // Default registry
        ProviderRegistry &ProviderRegistry::defaultRegistry() {
            static ProviderRegistry defaultRegistry{};
            return defaultRegistry;
        }

        // Get encoder provider
        std::shared_ptr<EncoderProviderFactory> ProviderRegistry::getEncoder(const MediaType &mediaType) {
            return encoderProviderFactories_.at(mediaType.str());
        }

        // Get decoder provider
        std::shared_ptr<DecoderProviderFactory> ProviderRegistry::getDecoder(const MediaType &mediaType) {
            return decoderProviderFactories_.at(mediaType.str());
        }

        // Register encoder provider for a media type
        void ProviderRegistry::registerEncoderProvider(const MediaType &mediaType,
                                                       std::shared_ptr<EncoderProviderFactory> factory) {
            encoderProviderFactories_[mediaType.str()] = factory;
        }

        // Register decoder provider for a media type
        void ProviderRegistry::registerDecoderProvider(const MediaType &mediaType,
                                                       std::shared_ptr<DecoderProviderFactory> factory) {
            decoderProviderFactories_[mediaType.str()] = factory;
        }
    }
}
