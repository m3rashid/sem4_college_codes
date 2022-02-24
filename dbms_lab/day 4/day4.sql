create table department(
  id int(5) not null primary key,
  name varchar(30) not null
);
insert into department
values (1, 'Information Technology');
insert into department
values (2, 'Electrical');
insert into department
values (3, 'Civil');
insert into department
values (4, 'Mechanical');
insert into department
values (5, 'Chemical');
create table stud_member(
  rollNo int(5) not null primary key,
  fName varchar(20),
  mName varchar(20),
  sName varchar(20),
  deptId integer(5) not null,
  semester integer(1) not null,
  contactNo integer(6),
  gender char not null
);
insert into stud_member
values (1, 'Ankur', 'Samir', 'Kahar', 1, 1, 272121, 'M');
insert into stud_member
values (
    2,
    'Dhaval',
    'Dhiren',
    'Joshi',
    1,
    1,
    232122,
    'M'
  );
insert into stud_member
values (3, 'Ankita', 'Viren', 'Shah', 1, 1, 112121, 'F');
insert into stud_member
values (
    10,
    'Komal',
    'MaheshKumar',
    'Pandya',
    2,
    1,
    123123,
    'F'
  );
insert into stud_member
values (
    13,
    'Amit',
    'JitenKumar',
    'Mehta',
    3,
    3,
    453667,
    'M'
  );
insert into stud_member
values (
    23,
    'Jinal',
    'Aashish',
    'Gandhi',
    2,
    1,
    323232,
    'M'
  );
insert into stud_member
values (22, 'Ganesh', 'Asha', 'Patel', 2, 3, 124244, 'M');
insert into stud_member
values (4, 'Shweta', 'Mihir', 'Patel', 3, 1, 646341, 'F');
insert into stud_member
values (7, 'Pooja', 'Mayank', 'Desai', 3, 3, 328656, 'F');
insert into stud_member
values (
    8,
    'Komal',
    'Krishnaraj',
    'Bhatia',
    2,
    3,
    257422,
    'F'
  );
insert into stud_member
values (43, 'Kiran', 'Viraj', 'Shah', 1, 1, 754124, 'F');
select fName,
  mName,
  sName,
  contactNo
from stud_member;
select fName,
  mName,
  sName,
  rollNo,
  deptId
from stud_member
where stud_member.deptId = 1;
select distinct name
from department,
  stud_member
where department.id = stud_member.deptId;
select name
from department
where department.id NOT IN (
    select deptId
    from stud_member
  );
select name
from department;
select COUNT(deptId)
from stud_member
where stud_member.deptId = 2;
select fName,
  mName,
  sName
from stud_member
where fName like 'A%';
select *
from stud_member
where stud_member.gender = 'M';
select *
from stud_member
where stud_member.semester = 3;
select *
from stud_member
where stud_member.gender = 'F'
order by fName;