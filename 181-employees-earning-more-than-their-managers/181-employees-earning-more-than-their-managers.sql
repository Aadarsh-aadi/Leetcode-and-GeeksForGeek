# Write your MySQL query statement below
select  b.name as Employee
from Employee as a , Employee as b
where a.id = b.managerId
and a.salary < b.salary
;