-- 1164: Product Price at a Given Date
-- Goal: Find the price of every product on 2019-08-16.
-- If no price change happened on/before that date → price = 10.


SELECT
    p.product_id,

    -- If a matching latest price exists, use it.
    -- If there is no matching row, LEFT JOIN gives NULL → use 10.
    COALESCE(lp.new_price, 10) AS price


FROM
    -- We need EVERY product in the final answer.
    -- Therefore, start with a list containing each product exactly once.
    (SELECT DISTINCT product_id
     FROM Products) AS p


LEFT JOIN
(
    -- ============================================================
    -- JOIN #1: Find the actual row containing the latest price
    -- ============================================================

    SELECT
        p1.product_id,
        p1.new_price

    FROM Products AS p1

    JOIN
    (
        -- First find the latest valid change DATE for each product.
        --
        -- MAX(change_date) gives us the latest date,
        -- but NOT the entire row / price.
        SELECT
            product_id,
            MAX(change_date) AS latest_change

        FROM Products

        -- Ignore future price changes.
        WHERE change_date <= '2019-08-16'

        -- Find the latest valid date separately for each product.
        GROUP BY product_id

    ) AS latest

        -- JOIN BACK to Products to retrieve the actual price
        -- belonging to that latest date.
        --
        -- We need BOTH conditions:
        -- 1. Same product
        -- 2. Exact latest date
        ON p1.product_id = latest.product_id
        AND p1.change_date = latest.latest_change


) AS lp

    -- ============================================================
    -- JOIN #2: Attach the latest price to EVERY product
    -- ============================================================

    ON p.product_id = lp.product_id;


-- Why LEFT JOIN here?
-- Because some products may have NO price change on/before
-- 2019-08-16.
--
-- We still need those products in the answer.
-- Their lp.new_price becomes NULL.
--
-- COALESCE(NULL, 10) → 10.