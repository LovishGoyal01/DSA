# Write your MySQL query statement below
with cte as (select product_id ,year , min(year) over(partition by product_id) as  first_year ,quantity ,price 
from Sales )

select product_id ,first_year ,quantity ,price
from cte 
where year = first_year
