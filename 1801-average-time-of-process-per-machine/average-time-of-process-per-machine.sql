# Write your MySQL query statement below
/*
select machine_id ,
ROUND(
    AVG(case when activity_type = 'end' then timestamp  
        else -timestamp 
        end)*2,3) as processing_time 
from Activity 
group by machine_id ;
*/
select s.machine_id ,
ROUND(AVG(e.timestamp - s.timestamp ),3) as processing_time 
from Activity s join Activity e on
e.machine_id =s.machine_id 
and e.process_id =s.process_id 
and e.activity_type ='end'
and s.activity_type ='start'
group by machine_id ;