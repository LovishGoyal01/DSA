# Write your MySQL query statement below

with cte as(select customer_id , count(DISTINCT product_key) as cn
from Customer 
group by customer_id)

select customer_id
from cte
where cn = (select count(DISTINCT product_key) from Product)