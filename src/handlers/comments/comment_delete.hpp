#pragma once

#include "handlers/common.hpp"

namespace posty::handlers::comments::del {

class Handler final : public Common {
public:
    static constexpr std::string_view kName = "handler-comment-delete";

    using Common::Common;

    userver::formats::json::Value HandleRequestJsonThrow(
        const userver::server::http::HttpRequest& request,
        const userver::formats::json::Value& request_json,
        userver::server::request::RequestContext& context
    ) const override;
};

}  // namespace posty::handlers::comments::del
