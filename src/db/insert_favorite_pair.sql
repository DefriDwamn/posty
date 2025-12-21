WITH tmp(article_id, user_id) AS (
    SELECT article_id, $1 FROM posty.articles WHERE slug=$2
)
INSERT INTO posty.favorites(article_id, user_id) (SELECT article_id, user_id FROM tmp)
ON CONFLICT DO NOTHING
RETURNING article_id
