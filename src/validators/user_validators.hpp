#pragma once

#include <regex>
#include <string_view>

namespace posty::validator {

bool ValidateEmail(const std::string& email);

bool ValidatePassword(const std::string& password);

bool ValidateUsername(const std::string& username);

}  // namespace posty::validator
