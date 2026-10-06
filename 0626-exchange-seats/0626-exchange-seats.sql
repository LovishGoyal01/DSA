# Write your MySQL query statement below
with cte as (select id, student, case when id mod 2=1 then lead(student) over (order by id asc) else lag(student) over (order by id asc) end as ns
from Seat)

select id, case when ns is not null then ns else student end as student 
from cte