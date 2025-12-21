#pragma once

#include "handlers/common.hpp"

namespace posty::handlers::profiles::del {

class Handler final : public Common {
public:
    static constexpr std::string_view kName = "handler-profile-unfollow";

    using Common::Common;

    userver::formats::json::Value HandleRequestJsonThrow(
        const userver::server::http::HttpRequest& request,
        const userver::formats::json::Value&,
        userver::server::request::RequestContext& context
    ) const override;
};

}  // namespace posty::handlers::profiles::del
