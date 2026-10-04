# Write your MySQL query statement below
with cte1 as(
    select s1.*,s2.subject_name 
    from  Students s1
    cross join Subjects s2
)

select c.student_id,c.student_name , c.subject_name, count(e.subject_name ) as attended_exams 
from cte1 as c
left join Examinations e
on c.student_id = e.student_id and c.subject_name = e.subject_name 
group by c.student_id ,c.subject_name 
order by student_id asc ,  subject_name ASC