INSERT INTO posty.users(username, email, bio, image, password_hash, salt)
VALUES($1, $2, $3, $4, $5, $6)
RETURNING *
