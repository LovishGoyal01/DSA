WITH cte AS (
    SELECT 
        p.product_id,
        (u.units * p.price) AS mult,
        u.units AS uni
    FROM Prices p
    LEFT JOIN UnitsSold u
        ON p.product_id = u.product_id
        AND u.purchase_date BETWEEN p.start_date AND p.end_date
)

SELECT 
    product_id,
    COALESCE(ROUND(SUM(mult) / SUM(uni), 2), 0) AS average_price
FROM cte
GROUP BY product_id;