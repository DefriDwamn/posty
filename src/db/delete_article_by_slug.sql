DELETE FROM posty.articles
WHERE slug = $1 AND user_id = $2
RETURNING article_id
