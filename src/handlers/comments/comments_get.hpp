#pragma once

#include "cache/comments_cache.hpp"
#include "handlers/common.hpp"

namespace posty::handlers::comments::get {

class Handler final : public Common {
public:
    static constexpr std::string_view kName = "handler-comments-get";

    Handler(
        const userver::components::ComponentConfig& config,
        const userver::components::ComponentContext& component_context
    );

    userver::formats::json::Value HandleRequestJsonThrow(
        const userver::server::http::HttpRequest& request,
        const userver::formats::json::Value& request_json,
        userver::server::request::RequestContext& context
    ) const override;

private:
    const posty::cache::comments_cache::CommentsCache& comments_cache_;
};

}  // namespace posty::handlers::comments::get
