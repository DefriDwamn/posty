#pragma once

#include <string>
#include <vector>

namespace posty::validator {

void ValidateTitle(const std::string& title);
void ValidateDescription(const std::string& description);
void ValidateBody(const std::string& body);
void ValidateTags(const std::vector<std::string>& tags);

}  // namespace posty::validator
