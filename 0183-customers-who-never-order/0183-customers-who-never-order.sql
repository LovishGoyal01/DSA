# Write your MySQL query statement below
select c.name as Customers 
from Customers c
where c.id NOT IN
(select c.id
from Customers c
inner join
Orders o
on c.id = o.customerId) 