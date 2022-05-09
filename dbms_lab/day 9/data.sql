create database `20BCS033_MD_Rashid_Hussain`;
use `20BCS033_MD_Rashid_Hussain`;
create table STudent (
    snum int,
    sname varchar(20),
    major varchar(20),
    level varchar(10),
    age int
);
create table CLass (
    cname varchar(20),
    meets_at varchar(20),
    room varchar(10),
    fid int
);
create table ENrolled (
    snum int,
    cname varchar(20)
);
create table FAculty (
    fid int,
    fname varchar(20),
    deptId int
);
 insert into STudent
     (snum, sname, major, level, age) values
     (101, 'John', 'CS', 'SR', 19),
     (102, 'Smith', 'CS', 'JR', 20),
     (103, 'Jacob', 'ECE', 'SR', 20),
     (104, 'Tom', 'CS', 'JR', 20),
     (105, 'Sid', 'CS', 'JR', 20),
     (106, 'Harry', 'History', 'SR', 21),
     (107, 'Hellen', 'CS', 'JR', 21),
     (108, 'Bob', 'English', 'SR', 22),
     (109, 'Andy', 'ECE', 'JR', 21),
     (110, 'Charles', 'History', 'SR', 23);
 insert into CLass (cname, meets_at, room, fid)
    values
    ('CSC342', 'Morning', 'R128', 201),
    ('CSC343', 'Noon', 'R128', 203),
    ('CSC345', 'Night', 'R154', 204),
    ('ECE300', 'Morning', 'R111', 202),
    ('ECE366', 'Noon', 'R111', 203),
    ('ENG366', 'Morning', 'R154', 203),
    ('ENG367', 'Evening', 'R111', 205),
    ('HIS320', 'Morning', 'R128', 205);
insert into ENrolled (snum, cname) 
    values
    (101, 'CSC342'),
    (101, 'CSC343'),
    (101, 'CSC345'),
    (101, 'ECE300'),
    (101, 'ENG366'),
    (102, 'CSC343'),
    (102, 'CSC345'),
    (102, 'ECE301'),
    (103, 'ECE300'),
    (103, 'ECE301'),
    (104, 'CSC342'),
    (104, 'ECE301'),
    (105, 'CSC345'),
    (105, 'ECE300'),
    (106, 'ENG366'),
    (106, 'HIS320'),
    (107, 'CSC342'),
    (107, 'ENG366'),
    (108, 'ENG367'),
    (108, 'HIS320'),
    (109, 'ECE300'),
    (109, 'ECE301'),
    (110, 'ENG366'),
    (110, 'HIS320');
insert into FAculty (fid, fname, deptId)
    values
    (201, 'S. Jackson', 301),
    (202, 'M. Shanks', 302),
    (203, 'I. Teach', 302),
    (204, 'A. Zobrah', 303),
    (205, 'M. Jensen', 303);
    