with cte as
(SELECT person_name,
       weight,
         SUM(weight) OVER (ORDER BY turn) AS cumulative_weight
FROM Queue q
ORDER BY turn)

select person_name
from cte 
where cumulative_weight <=1000
order by cumulative_weight desc
limit 1;