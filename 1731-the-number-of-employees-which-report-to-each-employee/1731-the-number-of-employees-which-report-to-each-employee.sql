# Write your MySQL query statement below
select e1.reports_to as employee_id ,e2.name,count(e1.employee_id) as reports_count , ROUND(AVG(e1.age)) AS average_age 
from Employees e1
join Employees e2
on e1.reports_to = e2.employee_id 
group by e1.reports_to 
order by e2.employee_id
