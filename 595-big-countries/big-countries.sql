# Write your MySQL query statement below

SELECT 
name, population, area 
FROM World 
WHERE area > (3000000 -1 ) OR population > (25000000 -1)
