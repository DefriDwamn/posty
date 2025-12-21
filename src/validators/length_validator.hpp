#pragma once

#include <regex>
#include <string_view>
#include <userver/utils/text.hpp>
#include "utils/errors.hpp"
#include "utils/make_error.hpp"

namespace posty::validator {

void CheckLength(const std::string& value, std::string_view fieldName, std::size_t minLen, std::size_t maxLen);

}  // namespace posty::validator
