CREATE DATABASE 20BCS033_MD_Rashid_Husain;
-- 
USE 20BCS033_MD_Rashid_Husain;
-- 
CREATE TABLE EMPLOYEE(
  Fname VARCHAR(15),
  Minit CHAR,
  Lname VARCHAR(15) NOT NULL,
  Ssn CHAR(9) NOT NULL,
  Bdate DATE,
  Address VARCHAR(30),
  Gender CHAR,
  Salary DECIMAL(10, 2),
  Super_ssn CHAR(9),
  Dno INT NOT NULL,
  PRIMARY KEY(Ssn)
);
-- 
DESCRIBE EMPLOYEE;
-- 
CREATE TABLE DEPARTMENT(
  Dname VARCHAR(15) NOT NULL,
  Dnumber INT NOT NULL,
  Mgr_ssn CHAR(9) NOT NULL,
  Mgr_start_date DATE,
  PRIMARY KEY(Dnumber),
  UNIQUE(Dname),
  FOREIGN KEY(Mgr_ssn) REFERENCES EMPLOYEE(Ssn)
);
-- 
DESCRIBE DEPARTMENT;
-- 
INSERT INTO EMPLOYEE
VALUES(
    'John',
    'B',
    'Smith',
    '123456789',
    '1965-01-09',
    '731 Fondren, Houston, TX',
    'M',
    30000,
    '333445555',
    5
  );
-- 
INSERT INTO EMPLOYEE
VALUES(
    'Franklin',
    'B',
    'Wong',
    '333445555',
    '1955-12-08',
    '638 Voss, Houston, TX',
    'M',
    40000,
    '888665555',
    5
  );
-- 
INSERT INTO EMPLOYEE
VALUES(
    'Alicia',
    'J',
    'Zelaya',
    '999887777',
    '1968-01-19',
    '3321
Castle, Spring, TX',
    'F',
    25000,
    '987654321',
    4
  );
-- 
INSERT INTO EMPLOYEE
VALUES(
    'Jennifer',
    'S',
    'Wallace',
    '987654321',
    '1941-06-20',
    '29
1 Berry, Bellaire, TX',
    'F',
    43000,
    '888665555',
    4
  );
-- 
INSERT INTO EMPLOYEE
VALUES(
    'Ramesh',
    'K',
    'Narayan',
    '666884444',
    '1962-09-15',
    '975
Fire Oak, Humble, TX',
    'M',
    38000,
    '333445555',
    5
  );
-- 
INSERT INTO EMPLOYEE
VALUES(
    'Joyce',
    'A',
    'English',
    '453453453',
    '1972-07-31',
    '5631
Rice, Houston, TX',
    'F',
    25000,
    '333445555',
    5
  );
-- 
INSERT INTO EMPLOYEE
VALUES(
    'Ahmad',
    'V',
    'Jabbar',
    '987987987',
    '1969-03-29',
    '980 Dallas, Houston, TX',
    'M',
    25000,
    '987654321',
    4
  );
-- 
INSERT INTO EMPLOYEE
VALUES(
    'James',
    'E',
    'Borg',
    '888665555',
    '1937-11-10',
    '450 Ston
e, Houston, TX',
    'M',
    55000,
    NULL,
    1
  );
-- 
SELECT *
FROM EMPLOYEE;
-- 
UPDATE EMPLOYEE
SET Minit = 'T'
WHERE Fname = 'Franklin';
-- 
SELECT *
FROM EMPLOYEE;
-- 
INSERT INTO DEPARTMENT
VALUES('Research', 5, '333445555', '1988-05-22');
-- 
INSERT INTO DEPARTMENT
VALUES('Administration', 4, '987654321', '1995-01-01');
-- 
INSERT INTO DEPARTMENT
VALUES('Headquarters', 1, '888665555', '1981-06-19');
-- 
SELECT *
FROM EMPLOYEE;
-- 
SELECT *
FROM DEPARTMENT;
-- 
SELECT Bdate,
  Address
FROM EMPLOYEE
WHERE Fname = 'John'
  AND Minit = 'B'
  AND Lname = 'Smith';
-- 
SELECT Fname,
  Lname,
  Address
FROM EMPLOYEE,
  DEPARTMENT
WHERE Dname = 'Research'
  AND Dnumber = Dno;
-- 
SELECT E.Fname,
  E.Lname,
  S.Fname,
  S.Lname
FROM EMPLOYEE AS E,
  EMPLOYEE AS S
WHERE E.Super_ssn = S.Ssn;
-- 
SELECT *
FROM EMPLOYEE;
-- 
SELECT *
FROM DEPARTMENT;
-- 
SELECT Ssn,
  Dname
FROM EMPLOYEE,
  DEPARTMENT;
-- 
SELECT Ssn
FROM EMPLOYEE;
-- 
SELECT Fname,
  Lname
FROM EMPLOYEE
WHERE Address LIKE '%Houston,TX%';
-- 
SELECT Fname,
  Lname
FROM EMPLOYEE
WHERE Address LIKE '%Houston, TX%';
-- 
SELECT ALL Salary
FROM EMPLOYEE;
-- 
SELECT DISTINCT Salary
FROM EMPLOYEE;
-- 
SELECT *
FROM EMPLOYEE
WHERE (
    Salary BETWEEN 30000 AND 40000
  )
  AND Dno = 5;
-- 
SELECT Fname,
  Lname
FROM EMPLOYEE
WHERE Bdate LIKE '_ _ 7 _ _ _ _ _ _ _';
-- 
SELECT Fname,
  Lname
FROM EMPLOYEE
WHERE Bdate LIKE '__7_______';