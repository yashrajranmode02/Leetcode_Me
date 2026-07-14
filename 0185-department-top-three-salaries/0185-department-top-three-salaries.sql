# Write your MySQL query statement below
WITH cte AS (
    SELECT *,
          dense_rank()  OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rd
    FROM Employee
)

SELECT
    d.name AS Department,
    cte.name AS Employee,
    cte.salary AS Salary
FROM cte
JOIN Department d
ON cte.departmentId = d.id
WHERE rd<=3