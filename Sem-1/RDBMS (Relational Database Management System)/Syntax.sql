CREATE TABLE table_name(
	Column_1_name Datatype(Size), 
	Column_2_name Datatype(Size), 
	Column_3_name Datatype(Size)
);

-- Ex. 
Create Table Student(
	rollno number(2),
	name varchar2(10),
	age number(2)
);

-- Create table with constraint 

CREATE TABLE student (
	rollno VARCHAR2(5) CHECK(rollno LIKE 'B%') PRIMARY KEY,
	name VARCHAR2(20) NOT NULL,
	pincode NUMBER(6) CHECK(LENGTH(pincode) = 6) NOT NULL,
	degree VARCHAR2(10) CHECK(degree IN('BCA', 'BCOM'))
);

-- foreign key 

CREATE TABLE teacher (
	t_id number(2) PRIMARY KEY,
	t_name varchar2(20),
	s_rollno number(2) References student(rollno) 
);

-- display table structure only 
DESC table_name;
Ex. 
DESC student;

-- select 
select * from CLIENT_MASTER;
select * from CLIENT_MASTER where c_no='C003';
select C_NO, CLIENT_NAME from CLIENT_MASTER;

-- Insert 
INSERT INTO student_tab(rollno, name, age) VALUES (1, 'a', 18);

-- Insert multiple row
INSERT INTO student_tab VALUES (&rollno, '&name', &age);

-- AS keyword (create + as)
create table client1 as select * from CLIENT_MASTER; 						-- copy full table with data
create table client2 as select * from CLIENT_MASTER where 12=10; 		-- only table structure copy 
create table client5 as select C_NO, CLIENT_NAME from CLIENT_MASTER; -- only this (C_NO, CLIENT_NAME) column add on client5 table

-- insert record from another table  (work wen only both table structure is same (column name, Datatype, all are same))
insert into client4 select * from CLIENT_MASTER								-- insert all record CLIENT_MASTER to client4
insert into client4 select * from CLIENT_MASTER where c_no='C003'; 	-- insert only this 'C003' record from CLIENT_MASTER add on client4 table;

-- AND -- both condition true then 
Select name from Student WHERE age=20 AND Name Like 'B%'; 
Select name from Student WHERE (age=20 AND Name Like 'B%');	-- both query are same

-- OR 	-- any one condition true then 
-- LIKE in select (need to write WHERE keyword)
Select name from Student WHERE Name LIKE 'A%' OR Name Like 'B%'; 	

-- Delete 
Delete from student; -- it deletes all rows from the student table (but not the table structure). 
Delete from student WHERE Rollno=1;

-- Update
Update EMP SET salary = 50000; -- this Update all rows
Update EMP SET salary = 50000 WHERE salary > 20000;

-- ALTER
ALTER TABLE Student ADD city VARCHAR2(15);  -- adds new column
ALTER TABLE Student DROP COLUMN city;  -- deletes a column
ALTER TABLE Student RENAME COLUMN age TO student_age; -- renames a column
ALTER TABLE Student RENAME TO Students; -- renames the table

-- ALTER with MODIFY
ALTER TABLE Student MODIFY name VARCHAR2(20); -- changes column size/type
ALTER TABLE Student MODIFY rollno NUMBER(3); -- change data type/size
ALTER TABLE Student MODIFY age DEFAULT 18; -- set default value
ALTER TABLE Student MODIFY name NOT NULL; -- make column NOT NULL

ALTER TABLE Student ADD CONSTRAINT chk_roll CHECK(rollno > 0); -- add check constraint
ALTER TABLE Student ADD CONSTRAINT chk_name CHECK(name LIKE 'B%'); -- check pattern

ALTER TABLE Student ADD pincode NUMBER(6); -- add new column

ALTER TABLE Student ADD CONSTRAINT chk_pin CHECK(LENGTH(pincode)=6); -- check length

ALTER TABLE Student ADD degree VARCHAR2(10); -- add new column

ALTER TABLE Student ADD CONSTRAINT chk_deg CHECK(degree IN('BCA','BCOM'));-- check allowed values

ALTER TABLE Student ADD CONSTRAINT pk_student PRIMARY KEY(rollno); -- set primary key

ALTER TABLE Student ADD dept_id NUMBER(2); -- add foreign key column

ALTER TABLE Student ADD CONSTRAINT fk_dept FOREIGN KEY(dept_id) REFERENCES Department(dept_id); -- add foreign key

-- renames the table
RENAME Student TO Students; 

-- Truncate
Truncate Table student; -- deletes all rows only (not destroy table structure) 

-- Drop
Drop Table student; -- destroy table data and structure both

-- distinct function 
select distinct(deptno) from emp; -- Display only unique departments (deptno) from EMP table

-- BETWEEN, ORDER BY
SELECT * FROM Student WHERE age BETWEEN 18 AND 25; -- use of BETWEEN (number range)
SELECT * FROM Student ORDER BY age; -- ascending order by number
SELECT * FROM Student ORDER BY name; -- ascending order by varchar
SELECT * FROM Student ORDER BY age DESC; -- descending order by number
SELECT * FROM Student ORDER BY name DESC; -- descending order by varchar

-- GROUP BY and HAVING
SELECT dept_id, COUNT(*) FROM Student GROUP BY dept_id; -- group by dept_id and count students
SELECT dept_id, AVG(age) FROM Student GROUP BY dept_id HAVING AVG(age) > 20; -- group by dept_id with average age greater than 20

-- IN, NOT IN, IS NULL, IS NOT NULL
SELECT * FROM Student WHERE name IN ('Amit', 'Vijay', 'Rahul'); -- use of IN (multiple value check)
SELECT * FROM Student WHERE name NOT IN ('Amit', 'Vijay', 'Rahul'); -- use of NOT IN (multiple value check)
SELECT * FROM Student WHERE name IS NULL; -- check for NULL value
SELECT * FROM Student WHERE name IS NOT NULL; -- check for NOT NULL value

-- Aggregate functions
SELECT COUNT(*) FROM Student; -- count total rows in Student table
SELECT AVG(age) FROM Student; -- average age from Student table
SELECT SUM(age) FROM Student; -- sum of age from Student table
SELECT MAX(age) FROM Student; -- maximum age from Student table
SELECT MIN(age) FROM Student; -- minimum age from Student table

-- String functions
SELECT name, LENGTH(name) FROM Student; -- get length of name column
SELECT name, UPPER(name) FROM Student; -- convert name to uppercase
SELECT name, LOWER(name) FROM Student; -- convert name to lowercase
SELECT name, SUBSTR(name, 1, 3) FROM Student; -- get substring of name (first 3 characters)
SELECT name, CONCAT(name, '_2024') FROM Student; -- concatenate '_2024' to name
SELECT name, TRIM(name) FROM Student; -- trim spaces from name

-- Numeric functions
SELECT name, ROUND(age, 0) FROM Student; -- round age to nearest integer
SELECT name, CEIL(age) FROM Student; -- ceiling value of age
SELECT name, FLOOR(age) FROM Student; -- floor value of age
SELECT name, MOD(age, 5) FROM Student; -- modulus of age by 5

-- SYSDATE , EXTRACT (), DATE FORMAT functions TO_CHAR (), TO_DATE ()
SELECT SYSDATE FROM dual; -- get current system date
SELECT name, EXTRACT(YEAR FROM SYSDATE) AS current_year FROM Student; -- extract current year
SELECT TO_CHAR(SYSDATE, 'DD-MON-YYYY') AS formatted_date FROM dual; -- format current date
SELECT name, SYSDATE - TO_DATE('2000-01-01', 'YYYY-MM-DD') AS days_since_2000 FROM Student; -- days since 1st Jan 2000
-- TO_DATE() function use to string into a date value, Converts the text '2000-01-01' into a real DATE value (1st Jan 2000)

select to_char(dob, 'Month dd, yyyy') from Student_Master; -- format date of birth column ex. February  12, 1998

SELECT name, EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM dob) AS age FROM Student_Master; -- calculate age from date of birth

-- JOIN examples
SELECT s.name, t.t_name FROM Student s JOIN Teacher t ON s.rollno = t.s_rollno; -- inner join
SELECT s.name, t.t_name FROM Student s LEFT JOIN Teacher t ON s.rollno = t.s_rollno; -- left join
SELECT s.name, t.t_name FROM Student s RIGHT JOIN Teacher t ON s.rollno = t.s_rollno; -- right join
SELECT s.name, t.t_name FROM Student s FULL JOIN Teacher t ON s.rollno = t.s_rollno; -- full join

-- 3 table join example
SELECT s.name, t.t_name, d.dept_name FROM Student s
JOIN Teacher t ON s.rollno = t.s_rollno
JOIN Department d ON t.dept_id = d.dept_id;

-- Subquery example
SELECT name FROM Student WHERE rollno IN (SELECT s_rollno FROM Teacher WHERE t_name = 'John Doe'); -- subquery to find students taught by 'John Doe'

-- create view
CREATE OR REPLACE VIEW Student_View AS SELECT name, age FROM Student; -- create view for all students
CREATE OR REPLACE VIEW Student_View AS SELECT name, age FROM Student WHERE age >= 18; -- create view for students aged 18 and above

create or replace view APPLICANT_view as select * from APPLICANT;
select * from APPLICANT_view; -- select through view
update APPLICANT_view set A_NAME='Dip' where A_NAME='Deepak'; -- update through view

drop view APPLICANT_view;	-- drop view

-- CASCADE CONSTRAINTS  -- table not dropped because of foreign key constraint, now we use CASCADE CONSTRAINTS
DROP TABLE Department CASCADE CONSTRAINTS; -- drop table along with its dependent constraints
-- means — when you drop the table, it also removes all related foreign key constraints in other tables that reference it.
-- For those tables and columns only the relationship is deleted, now that column behave like a normal column.


/*
General rules:
	- Both SELECT statements must return the same number of columns.
	- Corresponding columns must have compatible data types (or be cast).
	- Column order matters for matching rows; result column names come from the first SELECT.
	- The final result set has no guaranteed row order unless you use ORDER BY on the combined query.
	- You can apply ORDER BY only once, after the last SELECT of the set operation.

UNION:
	- Combines rows from both queries and returns only distinct (unique) rows.
	- Duplicate rows that appear in both queries are removed from the result.
	- Use when you want a combined list with duplicates eliminated.
	- Removing duplicates can be slower because the database must compare rows.

UNION ALL:
	- Combines rows from both queries and returns all rows, including duplicates.
	- Faster than UNION because it does not perform duplicate elimination.
	- Use when you want to preserve duplicates or when you know the results are already distinct.

INTERSECT:
	- Returns only the rows that appear in both queries (the intersection).
	- Duplicates are removed in the result (unless the DBMS supports INTERSECT ALL).
	- Use when you need the common records shared by both result sets.

MINUS / EXCEPT:
	- Returns rows from the first query that do NOT appear in the second query.
	- In many systems this is called EXCEPT; some systems use MINUS.
	- Duplicates are removed in the result (variants like EXCEPT ALL exist in some DBMS).
	- Use to find items present in one set but absent from another.

Performance tips:
	- Prefer UNION ALL when you do not need duplicate elimination.
	- Ensure appropriate indexing on the columns involved if joining or filtering before performing set operations.
	- If column types differ, CAST explicitly to avoid errors and make comparisons clear.
*/
-- Set operations
SELECT name FROM Student_A UNION SELECT name FROM Student_B; -- union of two student tables
SELECT name FROM Student_A UNION ALL SELECT name FROM Student_B; -- union all of two student tables
SELECT name FROM Student_A INTERSECT SELECT name FROM Student_B; -- intersection of two student tables
SELECT name FROM Student_A MINUS SELECT name FROM Student_B; -- difference of two student tables, records in Student_A but not in Student_B

-- Example tables for set operations
SQL> SELECT * FROM FYRankers;

 ENROL_NO   NAME             SPI
----------  ---------------- ----
         1  John Doe         8.2
         2  Jane Smith       7.5
         3  Emily Davis      6.9
         4  Michael Brown    8.7

SQL> SELECT * FROM SYRankers;

 ENROL_NO   NAME             SPI
----------  ---------------- ----
         3  Emily Davis      8.1
         4  Michael Brown    7.8
         5  Chris Lee        8.3
         6  Anna White       6.8

SQL> -- 1. Display the name of the student who is ranker in 'FY' or 'SY'
SELECT name FROM FYRankers UNION SELECT name FROM SYRankers; -- removes duplicate data, only unique names

NAME
--------------------
Anna White
Chris Lee
Emily Davis
Jane Smith
John Doe
Michael Brown

SQL> -- 2. Display the name of the student who is ranker in 'FY' or 'SY' including duplicate data
SELECT name FROM FYRankers UNION ALL SELECT name FROM SYRankers; -- all names including duplicates

NAME
--------------------
John Doe
Jane Smith
Emily Davis
Michael Brown
Emily Davis
Michael Brown
Chris Lee
Anna White

SQL> -- 3. Display the name of the students who is ranker in 'FY' or 'SY' and having SPI more than 7
SELECT name FROM FYRankers WHERE spi > 7 UNION SELECT name FROM SYRankers WHERE spi > 7;

NAME
--------------------
Chris Lee
Emily Davis
Jane Smith
John Doe
Michael Brown

SQL> -- 4. Display the name of the student who is ranker in both FY and SY
SELECT name FROM FYRankers INTERSECT SELECT name FROM SYRankers; -- common names in both tables

NAME
--------------------
Emily Davis
Michael Brown

SQL> -- 5. Display the name of the student who is ranker in FY but not in SY
SELECT name FROM FYRankers MINUS SELECT name FROM SYRankers; -- names in FY but not in SY

NAME
--------------------
Jane Smith
John Doe

SQL> -- 6. Display the name of the student who is ranker in SY but not in FY
SELECT name FROM SYRankers MINUS SELECT name FROM FYRankers; -- names in SY but not in FY

NAME
--------------------
Anna White
Chris Lee





-- Commit and Rollback
COMMIT; -- save changes
ROLLBACK; -- undo changes	

-- example of rollback
UPDATE Student SET age = age + 1 WHERE rollno = 1; -- update operation
select * from Student; -- verify the update
ROLLBACK; -- undo the update operation
select * from Student; -- verify rollback

-- Savepoint
SAVEPOINT sp1; -- create a savepoint	
ROLLBACK TO sp1; -- rollback to savepoint