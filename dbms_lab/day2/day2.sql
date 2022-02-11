CREATE TABLE Client_Master(
  ClientNo VARCHAR(6) NOT NULL,
  ClientName VARCHAR(20) NOT NULL,
  Address1 VARCHAR(30) NOT NULL,
  Address2 VARCHAR(30),
  City VARCHAR(15) NOT NULL,
  PinCode INT(8) NOT NULL,
  State VARCHAR(15) NOT NULL,
  BalDue DECIMAL(10, 2) NOT NULL,
  PRIMARY KEY(ClientNo)
);
CREATE TABLE Product_Master(
  ProductNo VARCHAR(6) NOT NULL,
  ProductName VARCHAR(20) NOT NULL,
  Quantity INT(5) NOT NULL,
  QtyOnHand INT(5) NOT NULL,
  Tax INT(2) NOT NULL,
  CostPrice DECIMAL(10, 2) NOT NULL,
  SalePrice DECIMAL(10, 2) NOT NULL,
  PRIMARY KEY(ProductNo)
);
INSERT INTO Client_Master
VALUES(
    'C00001',
    'Ivan Bayross',
    'Address 1',
    'Address 2',
    'Mumbai',
    '400001',
    'Maharashtra',
    15000.00
  );
INSERT INTO Client_Master
VALUES(
    'C00002',
    'Mamta Muzamdaar',
    'Address 1',
    'Address 2',
    'Madras',
    '7800001',
    'Tamil Nadu',
    0.00
  );
INSERT INTO Client_Master
VALUES(
    'C00003',
    'Chhaya Bankar',
    'Address 1',
    'Address 2',
    'Mumbai',
    '400057',
    'Maharashtra',
    5000.00
  );
INSERT INTO Client_Master
VALUES(
    'C00004',
    'Ashwini Joshi',
    'Address 1',
    'Address 2',
    'bangalore',
    '560001',
    'Karnataka',
    0.00
  );
INSERT INTO Client_Master
VALUES(
    'C00005',
    'Hansei Colaco',
    'Address 1',
    'Address 2',
    'Mumbai',
    '400060',
    'Maharashtra',
    2000.00
  );
INSERT INTO Client_Master
VALUES(
    'C00006',
    'Deepak Sharma',
    'Address 1',
    'Address 2',
    'Mangalore',
    '560050',
    'Karnataka',
    0.00
  );
INSERT INTO Product_Master
VALUES(
    'P00001',
    'T-Shirts',
    5,
    200,
    50,
    350.00,
    250.00
  );
INSERT INTO Product_Master
VALUES(
    'P0345',
    'Shirts',
    6,
    150,
    50,
    300.00,
    350.00
  );
INSERT INTO Product_Master
VALUES(
    'P06734',
    'Cotton Jeans',
    6,
    100,
    20,
    600.00,
    450.00
  );
INSERT INTO Product_Master
VALUES(
    'P07865',
    'Jeans',
    5,
    100,
    20,
    750.00,
    500.00
  );
INSERT INTO Product_Master
VALUES(
    'P07868',
    'Trousers',
    2,
    150,
    50,
    850.00,
    550.00
  );
INSERT INTO Product_Master
VALUES(
    'P07885',
    'Pull Overs',
    3,
    140,
    50,
    850.00,
    550.00
  );
INSERT INTO Product_Master
VALUES(
    'P07878',
    'Denim Shirts',
    4,
    100,
    40,
    350.00,
    250.00
  );
INSERT INTO Product_Master
VALUES(
    'P07887',
    'Lycra Tops',
    5,
    70,
    30,
    300.00,
    175.00
  );
INSERT INTO Product_Master
VALUES(
    'P07888',
    'Skirts',
    5,
    75,
    30,
    450.00,
    300.00
  );