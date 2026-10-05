# Write your MySQL query statement below
with cte as(
select customer_id ,order_date , customer_pref_delivery_date , row_number() over(PARTITION BY customer_id order by order_date asc) as rn
from  Delivery )

select round(sum(case when order_date = customer_pref_delivery_date and rn=1 then 1 else 0 end)*100/ count(distinct(customer_id)),2) as immediate_percentage 
from cte 



