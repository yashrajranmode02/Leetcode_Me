# Write your MySQL query statement below
select s1.name as name
from SalesPerson s1
WHERE s1.sales_id not in(
    select sales_id
    from Orders 
    where com_id not in(
        select com_id  from Company where name!="RED"
    )
)