#include "user.hpp"
#include "utils/jwt.hpp"

#include <userver/formats/serialize/common_containers.hpp>

namespace posty::models {

userver::formats::json::Value
Serialize(const User& user, userver::formats::serialize::To<userver::formats::json::Value>) {
    userver::formats::json::ValueBuilder item;
    item["email"] = user.email;
    item["username"] = user.username;
    item["token"] = utils::jwt::GenerateJWT(user.id);
    item["bio"] = user.bio ? user.bio.value() : std::string{};
    item["image"] = user.image ? user.image.value() : std::string{};
    return item.ExtractValue();
}

}  // namespace posty::models
