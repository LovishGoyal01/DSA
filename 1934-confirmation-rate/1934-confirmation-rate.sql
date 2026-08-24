# Write your MySQL query statement below
with cte as
(select user_id , round(sum(action = 'confirmed') /count(time_stamp),2) as confirmation_rate 
from Confirmations
group by user_id )

select s.user_id ,case when c.confirmation_rate is null then 0 else  c.confirmation_rate end as confirmation_rate 
from Signups s
left join
cte c
on s.user_id = c.user_id 