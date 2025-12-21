WITH tmp(article_id, user_id) AS (
    SELECT article_id, $1 FROM posty.articles WHERE slug=$2
)
DELETE FROM posty.favorites
WHERE (article_id, user_id) IN (SELECT article_id, user_id FROM tmp)
RETURNING article_id
