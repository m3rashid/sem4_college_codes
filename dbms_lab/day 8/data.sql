--  Question one
create table Passenger (
  pid int not null,
  pname varchar(10) not null,
  age int not null,
);
insert into Passenger
values (0, 'Sachin', 65);
insert into Passenger
values (1, 'Rahul', 66);
insert into Passenger
values (2, 'Sourav', 67);
insert into Passenger
values (3, 'Anil', 69);
create table Reservation (
  pid int not null,
  class varchar(10) not null,
  tid int not null,
);
insert into Reservation
values (0, 'AC', 8200);
insert into Reservation
values (1, 'AC', 8201);
insert into Reservation
values (2, 'SC', 8201);
insert into Reservation
values (5, 'AC', 8203);
insert into Reservation
values (1, 'SC', 8204);
insert into Reservation
values (3, 'AC', 8202);
-- 
-- 
-- Question two
create table Suppliers(
  sid int,
  sname varchar(255),
  city VARCHAR(255),
  street VARCHAR(255)
);
create table Parts(pid int, pname VARCHAR(255), color VARCHAR(255));
create table Catalog(sid int, pid int, cost DECIMAL(10, 2));
-- 
--
-- Question three
create table Employee (
  name VARCHAR(255),
  sex VARCHAR(10),
  salary int,
  deptName VARCHAR(255)
);
-- 
-- 
-- Question four
create table book (title VARCHAR(255), price int);
-- 
-- 
-- Question five
-- 
-- 
-- 
-- Question six
-- 
-- 
-- 
-- Question seven
create table Loan_Records (
  BorrowerBank_Manager VARCHAR(255),
  Loan_Amount decimal(10, 2),
);
-- 
-- 
-- Question eight
create table employee(
  empId int,
  name VARCHAR(255),
  department VARCHAR(255),
  salary int
);
-- 
-- 
-- Question nine
-- 
-- 
-- 
-- Question ten
create table Student(Roll_No int, Student_Name VARCHAR(255),);
create table Performance (
  Roll_No int,
  Course VARCHAR(255),
  Marks int,
);
insert into Student
VALUES (1, 'Raj');
insert into Student
VALUES (2, 'Rohit');
insert into Student
VALUES (3, 'Raj');
-- 
insert into Performance
VALUES(1, 'Math', 80);
insert into Performance
VALUES(1, 'English', 70);
insert into Performance
VALUES(2, 'Math', 75);
insert into Performance
VALUES(3, 'English', 80);
insert into Performance
VALUES(2, 'Physics', 65);
insert into Performance
VALUES(3, 'Math', 80);
-- 
-- 
-- Question eleven
create table Cinema (
  theater VARCHAR(255),
  address VARCHAR(255),
  capacity int
);