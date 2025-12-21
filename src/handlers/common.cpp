#include "common.hpp"

#include <userver/components/component_config.hpp>
#include <userver/components/component_context.hpp>
#include <userver/storages/postgres/component.hpp>

namespace posty::handlers {

Common::Common(const userver::components::ComponentConfig& config,
               const userver::components::ComponentContext& component_context)
    : HttpHandlerJsonBase(config, component_context),
      pg_cluster_(component_context
                      .FindComponent<userver::components::Postgres>(
                          postrgres_component_name)
                      .GetCluster()),
      articles_cache_(
          component_context
              .FindComponent<posty::cache::articles_cache::ArticlesCache>()) {}

}  // namespace posty::handlers
