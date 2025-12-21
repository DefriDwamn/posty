WITH article AS (
  SELECT article_id FROM posty.articles WHERE slug = $2
)
SELECT * FROM posty.comments
JOIN article ON article.article_id = posty.comments.article_id
WHERE comment_id = $1
