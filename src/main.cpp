#include <userver/clients/dns/component.hpp>
#include <userver/clients/http/component_list.hpp>
#include <userver/components/minimal_server_component_list.hpp>
#include <userver/server/handlers/ping.hpp>
#include <userver/server/handlers/tests_control.hpp>
#include <userver/storages/postgres/component.hpp>
#include <userver/testsuite/testsuite_support.hpp>
#include <userver/utils/daemon_run.hpp>

#include "handlers/auth/auth_bearer.hpp"

#include "handlers/profiles/profiles.hpp"
#include "handlers/profiles/profiles_follow.hpp"
#include "handlers/profiles/profiles_follow_delete.hpp"

#include "handlers/tags/tags.hpp"

#include "handlers/comments/comment_delete.hpp"
#include "handlers/comments/comment_post.hpp"
#include "handlers/comments/comments_get.hpp"

#include "handlers/users/user_get.hpp"
#include "handlers/users/user_put.hpp"
#include "handlers/users/users.hpp"
#include "handlers/users/users_login.hpp"

#include <string_view>
#include "cache/articles_cache.hpp"
#include "cache/comments_cache.hpp"
#include "handlers/articles/articles_favorite.hpp"
#include "handlers/articles/articles_get.hpp"
#include "handlers/articles/articles_post.hpp"
#include "handlers/articles/articles_slug_delete.hpp"
#include "handlers/articles/articles_slug_get.hpp"
#include "handlers/articles/articles_slug_put.hpp"
#include "handlers/articles/articles_unfavorite.hpp"
#include "handlers/articles/feed_articles.hpp"

using namespace posty::handlers;
static constexpr std::string_view postrgres_component_name = "posty-database";

int main(int argc, char* argv[]) {
  userver::server::handlers::auth::RegisterAuthCheckerFactory<
      posty::auth::CheckerFactory>();

  auto component_list =
      userver::components::MinimalServerComponentList()
          .Append<userver::server::handlers::Ping>()
          .Append<userver::components::TestsuiteSupport>()
          .Append<posty::cache::articles_cache::ArticlesCache>()
          .Append<posty::cache::comments_cache::CommentsCache>()
          .AppendComponentList(userver::clients::http::ComponentList())
          .Append<userver::components::Postgres>(postrgres_component_name)
          .Append<userver::clients::dns::
                      Component>()  // posty::handlers::users_login::post
          .Append<userver::server::handlers::TestsControl>()
          .Append<posty::handlers::users::put::Handler>()
          .Append<posty::handlers::users::get::Handler>()
          .Append<posty::handlers::comments::del::Handler>()
          .Append<posty::handlers::comments::post::Handler>()
          .Append<posty::handlers::comments::get::Handler>()
          .Append<posty::handlers::users::post::RegisterUser>()
          .Append<posty::handlers::profiles::get::Handler>()
          .Append<posty::handlers::profiles::post::Handler>()
          .Append<posty::handlers::profiles::del::Handler>()
          .Append<posty::handlers::tags::get::Handler>()
          .Append<posty::handlers::articles::feed::get::Handler>()
          .Append<posty::handlers::articles::get::Handler>()
          .Append<posty::handlers::articles::post::Handler>()
          .Append<posty::handlers::articles_slug::get::Handler>()
          .Append<posty::handlers::articles_slug::put::Handler>()
          .Append<posty::handlers::articles_slug::del::Handler>()
          .Append<posty::handlers::articles_favorite::post::Handler>()
          .Append<posty::handlers::articles_favorite::del::Handler>();

  posty::handlers::users_login::post::AppendLoginUser(component_list);

  return userver::utils::DaemonMain(argc, argv, component_list);
}