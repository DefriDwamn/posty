#pragma once

#include <optional>
#include <string>
#include <tuple>
#include <unordered_set>
#include "models/profile.hpp"
#include "models/user.hpp"

#include <userver/formats/json/value_builder.hpp>
#include <userver/storages/postgres/io/chrono.hpp>
#include <userver/storages/postgres/io/pg_types.hpp>

namespace posty::models {
using CommentId = int32_t;

struct Comment {
    CommentId id;
    userver::storages::postgres::TimePointTz created_at;
    userver::storages::postgres::TimePointTz updated_at;
    std::string body;
    std::string user_id;
    posty::handlers::Profile author;

    auto Introspect() { return std::tie(id, created_at, updated_at, body, user_id, author); }
};

struct CachedComment {
    CommentId id;
    userver::storages::postgres::TimePointTz created_at;
    userver::storages::postgres::TimePointTz updated_at;
    std::string body;
    std::string user_id;
    std::string slug;
    posty::models::User author;
    std::unordered_set<std::string> following;

    auto Introspect() { return std::tie(id, created_at, updated_at, body, user_id, slug, author, following); }
};

userver::formats::json::Value
Serialize(const Comment& comment, userver::formats::serialize::To<userver::formats::json::Value>);

}  // namespace posty::models

namespace userver::storages::postgres::io {

template <>
struct CppToUserPg<posty::models::CachedComment> {
    static constexpr DBTypeName postgres_name{"posty.comment"};
};

}  // namespace userver::storages::postgres::io
