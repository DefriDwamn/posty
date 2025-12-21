WITH comment AS (
    INSERT INTO posty.comments(body, user_id, article_id)
    VALUES ($1, $2, $3)
    RETURNING *
)
SELECT
    comment.comment_id,
    comment.created_at,
    comment.updated_at,
    comment.body,
    (
        SELECT
            ROW(users.username, users.bio, users.image, false)::posty.profile
        FROM posty.users
        WHERE user_id = $2
    ) AS author
FROM comment
