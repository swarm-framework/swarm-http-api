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

#ifndef SWARM_HTTP_HTTPPARAM_HXX
#define SWARM_HTTP_HTTPPARAM_HXX

#include <memory>
#include <string>

namespace swarm {
    namespace http {

        /// \brief Define an HTTP param like a key -> value object
        struct HTTPParam {

            /// \brief Get param key
            /// \return String containing key value
            virtual const std::string &key() const = 0;

            /// \brief Get raw param value
            /// \return String containing raw value
            virtual const std::string &rawValue() const = 0;

            /// \brief Get param value
            /// \return String containing raw value
            virtual const std::string &value() const = 0;

            // Virtual destructor
            virtual ~HTTPParam() {}

            /// \brief Create an HTTP parameter from non encoded value
            /// \param key Parameter key
            /// \param value Non encoded value
            /// \return Smart pointer containing http paramater
            static std::shared_ptr<HTTPParam> fromValue(const std::string &key, const std::string &value);

            /// \brief Create an HTTP parameter from encoded value
            /// \param key Parameter key
            /// \param value Encoded value
            /// \return Smart pointer containing http paramater
            static std::shared_ptr<HTTPParam> fromEncodedValue(const std::string &key, const std::string &encodedValue);
        };

        /// \brief Define an input http param
        /// Accept an encoded value and auto decode when using value
        class HTTPInputParam : public HTTPParam {

          private:
            /// \brief param key
            std::string key_;

            /// \brief Raw value (URL encoded)
            std::string rawValue_;

            /// \brief Decoded value
            mutable std::unique_ptr<std::string> value_;

          public:
            /// \brief Constructor with key and encoded value
            /// \param key Param key
            /// \param value Encoded value
            HTTPInputParam(const std::string &key, const std::string &value);

            /// \brief Get param key
            /// \return String containing key value
            virtual const std::string &key() const override;

            /// \brief Get raw param value
            /// \return String containing raw value
            virtual const std::string &rawValue() const override;

            /// \brief Get param value
            /// \return String containing decoded value
            virtual const std::string &value() const override;
        };

        /// \brief Define an output http param
        /// Accept an raw value and auto encode when using value
        class HTTPOutputParam : public HTTPParam {

          private:
            /// \brief param key
            std::string key_;

            /// \brief Raw value
            std::string rawValue_;

            /// \brief Encoded value
            mutable std::unique_ptr<std::string> value_;

          public:
            /// \brief Constructor with key and value
            /// \param key Param key
            /// \param value value
            HTTPOutputParam(const std::string &key, const std::string &value);

            /// \brief Get param key
            /// \return String containing key value
            virtual const std::string &key() const override;

            /// \brief Get raw param value
            /// \return String containing raw value
            virtual const std::string &rawValue() const override;

            /// \brief Get param value
            /// \return String containing encode value
            virtual const std::string &value() const override;
        };
    }
}

#endif // SWARM_HTTP_HTTPPARAM_HXX
