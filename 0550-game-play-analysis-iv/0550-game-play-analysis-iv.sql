# Write your MySQL query statement below
with cte as
(select player_id ,event_date ,  lead(event_date) over(partition by player_id order by event_date asc) as next,
row_number() over (partition by player_id order by event_date asc) as rn
from Activity )

select round(sum(case when DATEDIFF(next,event_date)=1 and rn=1 then 1 else 0 end ) / COUNT(DISTINCT player_id) ,2) as fraction  
from cte