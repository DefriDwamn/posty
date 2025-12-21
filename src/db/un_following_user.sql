WITH profile AS (
  SELECT * FROM posty.users WHERE user_id = $1
), following AS (
  DELETE FROM posty.followers WHERE followed_user_id = $1 AND follower_user_id = $2
  RETURNING *
)
SELECT
  profile.username,
  profile.bio,
  profile.image,
  CASE WHEN EXISTS (SELECT 1 FROM following) THEN FALSE ELSE TRUE END
FROM profile
