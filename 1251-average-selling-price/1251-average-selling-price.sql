# Write your MySQL query statement below
SELECT p.product_id, 
ROUND(
    CASE
        WHEN count(u.units) = 0 THEN 0
        ELSE 1.0 * SUM(p.price * u.units) / SUM(u.units)
    END,
2) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id