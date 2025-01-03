# Write your MySQL query statement below
select 
eu.unique_id as unique_id, e.name as name
from Employees AS e left join EmployeeUNI AS eu on e.id = eu.id