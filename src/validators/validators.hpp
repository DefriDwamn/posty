#pragma once

#include <docs/api/api.hpp>

namespace posty::validator {

void validate(const handlers::UserLoginDTO& dto);

void validate(const handlers::UserRegistrationDTO& dto);

void validate(const handlers::UserUpdateDTO& dto);

void validate(const handlers::AddComment& dto);

void validate(const handlers::CreateArticleRequest& dto);

void validate(const handlers::UpdateArticleRequest& dto);

}  // namespace posty::validator
