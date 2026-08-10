# Write your MySQL query statement below
SELECT
MAX(CASE WHEN c.num_count = 1 THEN num
END) AS num
FROM
(SELECT num, COUNT(num) AS num_count
FROM MyNumbers
GROUP BY num) c