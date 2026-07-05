SELECT  
    CASE 
    when id=(
        select max(id) from Seat
    ) and id%2!=0 then id
    WHEN id%2!=0 then id+1
         WHEN id%2=0 then id-1
         end  
         as id,student 
FROM Seat 
order by id