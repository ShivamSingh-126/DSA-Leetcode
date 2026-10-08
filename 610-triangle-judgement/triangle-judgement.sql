# Write your MySQL query statement below
-- select x,y,z,
-- CASE 
--     WHEN 
--     x+y > z AND
--     x+z > y AND
--     y+z > x 
--     THEN 'Yes'
--     ELSE 'No'
--     END as triangle
--     from Triangle;

select * ,if(x+y >z and x+z>y and y+z > x ,"Yes","No")as triangle from Triangle;