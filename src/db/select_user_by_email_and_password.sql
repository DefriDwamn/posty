SELECT * FROM posty.users
WHERE email = $1 AND password_hash = $2
