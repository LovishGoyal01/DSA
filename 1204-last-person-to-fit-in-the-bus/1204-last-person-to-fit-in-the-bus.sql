# Write your MySQL query statement below
with cte as
(select *, sum(weight) over(order by turn asc) as wb
from Queue)

select person_name 
from cte 
where wb<=1000
order by wb desc
limit 1