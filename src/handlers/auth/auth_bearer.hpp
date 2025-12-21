#pragma once

#include <userver/server/handlers/auth/auth_checker_factory.hpp>
#include <userver/storages/postgres/postgres_fwd.hpp>

namespace posty::auth {

class CheckerFactory final
    : public userver::server::handlers::auth::AuthCheckerFactoryBase {
 public:
  static constexpr std::string_view kAuthType = "bearer";

  explicit CheckerFactory(const userver::components::ComponentContext& context);

  userver::server::handlers::auth::AuthCheckerBasePtr MakeAuthChecker(
      const userver::server::handlers::auth::HandlerAuthConfig&) const override;

 private:
  userver::storages::postgres::ClusterPtr pg_cluster_;
  static constexpr std::string_view postrgres_component_name = "posty-database";
};

}  // namespace posty::auth
