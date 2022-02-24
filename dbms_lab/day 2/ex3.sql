-- EX 3
-- a
SELECT ClientName
FROM Client_Master;
-- b
SELECT *
FROM Client_Master;
-- c
SELECT City,
  State
FROM Client_Master;
-- d
SELECT ProductName
FROM Product_Master;
-- e
SELECT ClientName
FROM Client_Master
WHERE City = 'Mumbai';
-- 
-- 
-- EX 4
-- a
UPDATE Client_Master
SET City = 'Bangalore',
  State = 'Karnataka'
WHERE ClientNo = 'C00005';
-- b
UPDATE Client_Master
SET BalDue = 1000.00
WHERE ClientNo = 'C00001';
-- c
UPDATE Product_Master
SET CostPrice = 950.00
WHERE ProductName = 'Trousers';