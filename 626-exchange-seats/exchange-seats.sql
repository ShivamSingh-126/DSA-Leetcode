# Write your MySQL query statement below
select 
CASE
    when id %2 =1 AND id = (select max(id) from Seat) then id
    WHEN id % 2 =1 THEN  id+1
    else id-1
    END as id,
student
from Seat
order by id asc;