# Write your MySQL query statement below
SELECT emp.name, E.unique_id from Employees emp left join EmployeeUNI E ON emp.id = E.id;