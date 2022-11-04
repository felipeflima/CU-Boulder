DROP DATABASE IF EXISTS FINAL;
CREATE DATABASE FINAL;

USE FINAL;

-- DROP TABLE IF EXISTS T1;
-- CREATE TABLE T1
-- (
-- C1 INT (10) PRIMARY KEY,
-- C2 INT (10),
-- C3 INT (10) NOT NULL,
-- C4 VARCHAR (40) DEFAULT 'Data Analyst',
-- CHECK (C2>C3),
-- CHECK (C3 != 0)
-- );

-- DROP TABLE IF EXISTS T2;
-- CREATE TABLE T2
-- (
-- C5 INT (10) PRIMARY KEY,
-- C6 INT (10)
-- );


-- INSERT INTO T1(C1,C2,C3) VALUES
-- (4,2,1);

-- INSERT INTO T2(C5,C6) VALUES
-- (2,3);

-- SELECT * FROM T1;
-- SELECT * FROM T2;


DROP TABLE IF EXISTS Employees;
CREATE TABLE Employees
(
EmpId INT PRIMARY KEY AUTO_INCREMENT,
ManagerId INT,
NameE VARCHAR (45),
Department VARCHAR (45),
Salary INT, 
City VARCHAR (45)
);

INSERT INTO Employees VALUES
(1,	0, "Alex Smith", "Admin",90000,"Boulder"),
(2,	1, "Amy Mars", "Admin",50000,"Longmont"),
(3,	1, "Logan Mars", "Admin",70000,"Longmont"),
(4,	1, "James Mont", "Marketing",55000,""),
(5,	6, "John Smith", "Marketing",60000,"Boulder"),
(6,	1, "Lily Mars", "Marketing",95000,""),
(7,	6, "Ravi Grace", "Database",75000,"Longmont"),
(8,	6, "Tara Frank", "Database",80000,"Longmont"),
(9,	6, "Tom Ford", "Database",65000,""),
(10,6, "William Cruze", "Database",85000,"Longmont");


SELECT * FROM Employees;

SELECT Namee, Salary FROM(SELECT Namee, Salary,
RANK () OVER (
ORDER BY Salary DESC
) ranking
FROM Employees)t1
WHERE ranking = 5;

SELECT Namee, Salary FROM Employees ORDER BY `Salary` DESC LIMIT 4,1;


SELECT Department, COUNT(Department) AS Count
	FROM Employees
    GROUP BY Department
    HAVING Count > 3;


SELECT Namee, Department, IF (City IS NULL, "Broomfield", City) AS City
	FROM Employees;

INSERT INTO Employees(EmpId,ManagerId, NameE, Department, Salary) VALUES
(11,	0, "Alex Smith", "Admin",90000);


SELECT e.Namee
 FROM employees e
 INNER JOIN employees m
 ON (e.EmpId = m.ManagerId)
 GROUP BY e.Namee;
 
 
SELECT MAX(Salary)AS "Max", MIN(Salary) AS "Min", AVG(Salary) AS "Avg"
	FROM Employees;
    
    
SELECT Namee, Department, Salary
	FROM Employees
    WHERE Salary > (SELECT AVG(Salary) AS "Avg" FROM Employees GROUP BY Department)
    GROUP BY Namee, Department, Salary;
    
SELECT AVG(Salary) AS "Avg" FROM Employees GROUP BY Department;
