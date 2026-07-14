SELECT  c.name AS Customers
FROM Customers c
WHERE c.id NOT IN (
    SELECT customerId
    FROM Orders
    WHERE customerId IS NOT NULL
);
