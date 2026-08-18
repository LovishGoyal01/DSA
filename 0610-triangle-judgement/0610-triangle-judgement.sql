# Write your MySQL query statement below

select *, case when x+y > z and x+z > y  and z+y > x then 'Yes'
else 'No' END AS triangle
from triangle 
