#include <userver/cache/base_postgres_cache.hpp>
#include <userver/storages/postgres/io/chrono.hpp>
#include <userver/storages/postgres/query.hpp>
#include <userver/utils/algo.hpp>

#include "comments_cache.hpp"
#include "db/sql.hpp"

namespace posty::cache::comments_cache {

userver::storages::postgres::Query CommentCachePolicy::kQuery = posty::sql::kSelectCachedComments;

void CommentsCacheContainer::insert_or_assign(
    posty::cache::comments_cache::CommentsCacheContainer::Key&& comment_id,
    posty::cache::comments_cache::CommentsCacheContainer::Comment&& comment
) {
    auto comment_ptr = std::make_shared<const Comment>(std::move(comment));
    if (comment_to_key_.count(comment_id)) {
        auto& old_slug = comment_to_key_[comment_id]->slug;
        if (old_slug != comment_ptr->slug) {
            auto& comments = comments_to_slug_[old_slug];
            comments_to_slug_[comment_ptr->slug] = comments;
            comments_to_slug_.erase(old_slug);
        }
    }
    comment_to_key_.insert_or_assign(comment_id, comment_ptr);
    comments_to_slug_[comment_ptr->slug].insert_or_assign(comment_id, comment_ptr);
};

size_t CommentsCacheContainer::size() const { return comment_to_key_.size(); }

std::map<CommentsCacheContainer::Key, CommentsCacheContainer::CommentPtr> CommentsCacheContainer::findComments(
    const Slug& slug
) const {
    if (!comments_to_slug_.count(slug)) return {};
    return comments_to_slug_.at(slug);
}

}  // namespace posty::cache::comments_cache
