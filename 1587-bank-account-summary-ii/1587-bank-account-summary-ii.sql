# Write your MySQL query statement below
with cte as(
select account, sum(amount) as balance
from Transactions t
group by account 
having balance >10000)

select u.name,c.balance
from cte c
left join Users u
on c.account  = u.account   