-- Create DB CSStudent
DROP SCHEMA IF EXISTS `CSStudent` ;
CREATE SCHEMA IF NOT EXISTS `CSStudent` DEFAULT CHARACTER SET utf8 ;
USE `CSStudent` ;

-- Create Table Student
DROP TABLE IF EXISTS Student;
CREATE TABLE IF NOT EXISTS Student (
	studentid INT PRIMARY KEY,
    class VARCHAR(40) DEFAULT 'CS',
    pay DECIMAL(5,2),
    skill VARCHAR(4)
);

DESC Student;

-- Modify Student Table 
	

ALTER TABLE Student
		ADD pay_date DATE AFTER pay;
        
ALTER TABLE Student
	 MODIFY pay DECIMAL(10,2);

ALTER TABLE Student
	MODIFY studentid INT AUTO_INCREMENT;
    
ALTER TABLE Student
	AUTO_INCREMENT = 10;
    
DESC Student;
SELECT * FROM Student;

-- Insert in Students

ALTER TABLE Student
	 MODIFY skill VARCHAR(40);

INSERT INTO Student (studentid,class,pay,pay_date,skill)
	VALUES (1,'Phy',15.99,'2020/2/1',"Programming");
    
INSERT INTO Student (class,pay,pay_date,skill)
	VALUES ('Bio',10.00,'2020/2/1',"Jumping");

ALTER TABLE Student
	 DROP skill;
     
-- Update Student so studentid = 10 has will get a 10% increase

UPDATE Student
	SET pay = pay*1.1
    WHERE studentid = 10;

-- Create INDEX on column class
CREATE INDEX IX_class ON Student (class);
SHOW INDEX FROM Student;

-- Creat a view Where class = Bio
CREATE VIEW student_view AS
	SELECT * FROM Student 
    WHERE class = 'Bio';

SELECT * FROM Student;
SELECT * FROM student_view;

-- Create backup table from student table for studentid > 10

CREATE TABLE student_backup
	SELECT * FROM student
	WHERE studentid > 10;
    
SELECT * FROM student_backup;


-- remove all sata from student but keep table structure

TRUNCATE Student;
DELETE FROM Student;

-- Drop table Student and db CSStudent
USE CSStudent;

DROP TABLE Student;
DROP DATABASE CSStudent;




    