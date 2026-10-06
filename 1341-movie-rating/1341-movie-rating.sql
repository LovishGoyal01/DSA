WITH cte1 AS (
    SELECT 
        u.name,
        COUNT(*) AS cn
    FROM Users u
    JOIN MovieRating mr
        ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
),
cte2 AS (
    SELECT 
        m.title,
        AVG(mr.rating) AS ag
    FROM Movies m
    JOIN MovieRating mr
        ON m.movie_id = mr.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id, m.title
)

(
    SELECT name AS results
    FROM cte1
    ORDER BY cn DESC, name ASC
    LIMIT 1
)

UNION ALL

(
    SELECT title AS results
    FROM cte2
    ORDER BY ag DESC, title ASC
    LIMIT 1
);