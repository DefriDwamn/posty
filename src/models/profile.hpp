#pragma once

#include <userver/storages/postgres/io/io_fwd.hpp>
#include <userver/storages/postgres/io/pg_types.hpp>

#include <docs/api/api.hpp>

namespace userver::storages::postgres::io {

template <>
struct CppToUserPg<posty::handlers::Profile> {
    static constexpr DBTypeName postgres_name{"posty.profile"};
};

}  // namespace userver::storages::postgres::io
