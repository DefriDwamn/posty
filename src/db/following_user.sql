WITH profile AS (
  SELECT * FROM posty.users WHERE user_id = $1
), following AS (
  INSERT INTO posty.followers(followed_user_id, follower_user_id) VALUES ($1, $2)
  ON CONFLICT DO NOTHING
  RETURNING *
)
SELECT
  profile.username,
  profile.bio,
  profile.image,
  CASE WHEN EXISTS (SELECT 1 FROM following) THEN TRUE ELSE FALSE END
FROM profile
