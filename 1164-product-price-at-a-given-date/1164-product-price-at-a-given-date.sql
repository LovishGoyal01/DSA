WITH cte AS (
    SELECT 
        product_id,
        MAX(change_date) AS latest_date
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

SELECT 
    p.product_id,
    p.new_price AS price
FROM Products p
JOIN cte c
    ON p.product_id = c.product_id
    AND p.change_date = c.latest_date

UNION

SELECT 
    product_id,
    10 AS price
FROM Products
GROUP BY product_id
HAVING MIN(change_date) > '2019-08-16';