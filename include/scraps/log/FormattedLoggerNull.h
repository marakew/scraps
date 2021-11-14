/**
* Copyright 2016 BitTorrent Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#pragma once

#include <scraps/config.h>

#include <scraps/log/LoggerInterface.h>
#include <scraps/log/FormatterInterface.h>

#include <string>

namespace scraps::log {

class FormattedLoggerNull : public FormattedLogger {
public:
    FormattedLoggerNull() {}

    /**
    * Formats a message and passes it to log(level, formattedMessage).
    */
    virtual void log(Message message) override {}

    /**
    * Override to write a formatted message.
    *
    * This implementation should be thread-safe.
    */
    virtual void write(Level level, const std::string& formattedMessage) {}
};

} // namespace scraps::log
