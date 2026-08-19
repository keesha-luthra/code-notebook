SELECT
    p.product_id,
    COALESCE(lp.new_price, 10) AS price
FROM
    (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN
    (
        SELECT
            p1.product_id,
            p1.new_price
        FROM Products p1
        JOIN
        (
            SELECT
                product_id,
                MAX(change_date) AS latest_change
            FROM Products
            WHERE change_date <= '2019-08-16'
            GROUP BY product_id
        ) AS latest
        ON p1.product_id = latest.product_id
        AND p1.change_date = latest.latest_change
    ) AS lp
    ON p.product_id = lp.product_id;