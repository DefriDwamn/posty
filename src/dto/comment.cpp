#include "comment.hpp"

namespace posty::dto {

Comment Comment::Parse(const posty::models::CachedComment& cachedComment, std::optional<std::string> userId) {
    Comment comment;
    comment.id = cachedComment.id;
    comment.body = cachedComment.body;
    comment.updatedAt = cachedComment.updated_at;
    comment.createdAt = cachedComment.created_at;
    comment.author.username = cachedComment.author.username;
    comment.author.bio = cachedComment.author.bio ? cachedComment.author.bio.value() : std::string{};
    comment.author.image = cachedComment.author.image ? cachedComment.author.image.value() : std::string{};
    comment.author.following = !userId.has_value() ? false : cachedComment.following.count(*userId);
    return comment;
}

userver::formats::json::Value
Serialize(const Comment& comment, userver::formats::serialize::To<userver::formats::json::Value>) {
    userver::formats::json::ValueBuilder item;

    item["id"] = comment.id;
    item["createdAt"] = comment.createdAt;
    item["updatedAt"] = comment.updatedAt;
    item["body"] = comment.body;
    item["author"] = comment.author;

    return item.ExtractValue();
}

}  // namespace posty::dto
