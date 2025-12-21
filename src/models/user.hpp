#pragma once

#include <optional>
#include <string>
#include <tuple>

#include <userver/formats/json/value_builder.hpp>
#include <userver/storages/postgres/io/io_fwd.hpp>
#include <userver/storages/postgres/io/pg_types.hpp>

namespace posty::models {

using UserId = std::string;
struct User final {
    UserId id;
    std::string username;
    std::string email;
    std::optional<std::string> bio;
    std::optional<std::string> image;
    std::string password_hash;
    std::string salt;

    auto Introspect() { return std::tie(id, username, email, bio, image, password_hash, salt); }
};

userver::formats::json::Value
Serialize(const User& user, userver::formats::serialize::To<userver::formats::json::Value>);

}  // namespace posty::models

namespace userver::storages::postgres::io {

template <>
struct CppToUserPg<posty::models::User> {
    static constexpr DBTypeName postgres_name{"posty.user"};
};

}  // namespace userver::storages::postgres::io
