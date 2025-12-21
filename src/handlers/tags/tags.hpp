#pragma once

#include "handlers/common.hpp"

namespace posty::handlers::tags::get {

class Handler final : public Common {
public:
    static constexpr std::string_view kName = "handler-get-tags";

    using Common::Common;

    userver::formats::json::Value
    HandleRequestJsonThrow(const userver::server::http::HttpRequest&, const userver::formats::json::Value&, userver::server::request::RequestContext&)
        const override;
};

}  // namespace posty::handlers::tags::get
