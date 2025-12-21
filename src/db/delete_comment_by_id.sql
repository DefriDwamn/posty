DELETE FROM posty.comments
WHERE comment_id = $1 AND user_id = $2
RETURNING *
