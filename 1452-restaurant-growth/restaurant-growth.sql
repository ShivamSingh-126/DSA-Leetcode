# Write your MySQL query statement below
-- select 
-- SUM(amount),
-- ROUND(SUM(amount) / 7,2) as average_amount 

-- from Customer
-- group by visited_on
-- order by visited_on;

SELECT visited_on, amount, ROUND(amount/7, 2) AS average_amount
FROM (SELECT DISTINCT visited_on, 
SUM(amount) OVER(ORDER BY visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW) AS amount,
MIN(visited_on) OVER() AS first FROM Customer)t 
WHERE visited_on >= first+6;