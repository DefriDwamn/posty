#pragma once

#include <string_view>
#include <userver/formats/json/value.hpp>

namespace posty::utils::error {
userver::formats::json::Value MakeError(std::string_view field_name, std::string_view message);
}
