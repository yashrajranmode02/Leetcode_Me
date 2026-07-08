-- # Write your MySQL query statement below
with cte as(
    select *,
    RANK() over(
         partition by email   
         order by id   
    )as rd
    from Person 
)
delete from Person 
where id in (
    select id from cte 
    where rd>1
)
-- where rd>1

-- delete from Person where (id,email) not in (select min(id) as id , email from Person group by email)