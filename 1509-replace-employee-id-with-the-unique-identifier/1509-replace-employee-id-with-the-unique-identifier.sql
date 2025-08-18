# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id, Employees.name
FROM EmployeeUNI
RIGHT OUTER JOIN Employees
ON EmployeeUNI.id = Employees.id 