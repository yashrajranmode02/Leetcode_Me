select e2.unique_id ,e.name
from Employees e
left join EmployeeUNI e2
on e.id =e2.id