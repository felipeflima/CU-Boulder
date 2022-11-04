DROP DATABASE IF EXISTS exam; 
CREATE DATABASE exam;
USE exam;

DROP TABLE IF EXISTS TableA ; 
CREATE TABLE  TableA  
   (
   emp_id    int   unique  NOT NULL PRIMARY KEY,
   salary      int
   ) ;
   
INSERT INTO TableA VALUES (1, 10);
INSERT INTO TableA VALUES (10, 20);
 
 SELECT * from TableA;
 
 UPDATE TableA 
 SET salary = salary + 100
    	WHERE emp_id = 10;
        
        
SELECT salary, emp_id, COUNT(*) AS Count
	FROM TableA
    GROUP BY salary, emp_id;
    
SELECT a.salary
FROM TableA a
INNER JOIN TableA b
ON (a.salary = b.salary);

DROP TABLE IF EXISTS Customer ; 
CREATE TABLE  Customer  
   (
   customer_id    VARCHAR(40)  unique NOT NULL PRIMARY KEY,
   first_name VARCHAR(40),
   last_name  VARCHAR(40),
   job_title  VARCHAR(40)
   ) ;
   
INSERT INTO Customer VALUES ("C001", "John", "Kelly", "DBA");
INSERT INTO Customer VALUES ("C002", "Amelia", "Cruze", "DBA");
INSERT INTO Customer VALUES ("C003", "Sohpia", "Henry",	"Cashier");
INSERT INTO Customer VALUES ("C004", "Tom",	"Smith", "QA");
INSERT INTO Customer VALUES ("C005", "Mia",	"Stark", "Cashier");

SELECT * FROM Customer;
   
DROP TABLE IF EXISTS Orders; 
CREATE TABLE  Orders  
   (
   order_id int  unique NOT NULL PRIMARY KEY,
   customer_id   VARCHAR(40),
   order_date DATE,
   shipping_company VARCHAR(40),
   FOREIGN KEY (customer_id) REFERENCES Customer(customer_id)
   ) ;
   

INSERT INTO Orders VALUES (1,	"C001",	'2019/9/27',	"FedEx");
INSERT INTO Orders VALUES (2,	"C002",	'2019/9/30',	"UPS");
INSERT INTO Orders VALUES (3,	"C002",	'2019/8/15',	"UPS");
INSERT INTO Orders VALUES (4,	"C005", '2019/8/20',	"FedEx");
INSERT INTO Orders VALUES (5,	"C005",	'2019/9/15',	"UPS");

SELECT * FROM Orders;
-- 1.	Select full name (i.e. first_name and last_name) and job_title whose customers records exists in 
-- customers table but NOT in orders table using sub-query.	


SELECT C.first_name, C.last_name, C.job_title
	FROM Customer C
    WHERE C.customer_id NOT IN (SELECT O.customer_id FROM Orders O);

-- 2.	Select first_name, last_name, shipping_company and order_date for all records from Customers table 
-- but ONLY matching records from Orders table for order_date after August 31st 2019.

SELECT C.first_name, C.last_name, O.shipping_company, O.order_date
	FROM Customer C
	INNER JOIN Orders O ON (C.customer_id = O.customer_id)
	WHERE O.order_date > '2019/08/31';
    
-- 3.	Write a SQL statement selecting shipping_company, order_date and their rank with most recent order_date rank first and so on.	

SELECT shipping_company, order_date,
	RANK () OVER ( 
		ORDER BY order_date DESC
	) ranking 
	FROM Orders;
    
  -- 4.	Select first_name, last_name and shipping_company for matching records from both tables for customers 
  -- first_name ends with a and sort by most recent order_date first.
  
  SELECT C.first_name, C.last_name, O.shipping_company
	FROM Customer C
	INNER JOIN Orders O ON (C.customer_id = O.customer_id)
    WHERE C.first_name LIKE '%a';

-- 5.	Write a SQL statement to find shipping_company and their count whose count is greater than 2.		

SELECT shipping_company, COUNT(shipping_company) AS count
	FROM Orders
    GROUP BY shipping_company
    HAVING count > 2;


    
    
    
    
    
    
    
    
    
    

