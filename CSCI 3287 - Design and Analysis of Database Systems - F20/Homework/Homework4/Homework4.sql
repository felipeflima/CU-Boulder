USE `HW_4_SQL`;

-- 1. Show a list the Company Name and Country for all Suppliers located in Japan or Germany.
SELECT CompanyName, Country
	FROM hwSuppliers
	WHERE Country = "Japan" OR Country = "Germany";
    
-- 2. Show a list of Product Name, Quantity per Unit and Unit Price for products with a Unit Price less than $7 but more than $ 4.
SELECT ProductName, QuantityPerUnit, UnitPrice
	FROM hwProducts
    WHERE UnitPrice > 4 AND UnitPrice < 7;
    
-- 3. Show a list of Company Name, City and Country for Customers whose Country is USA and City is Portland OR Country is Canada and City is Vancouver.
SELECT CompanyName, City, Country
	FROM hwCustomers
    WHERE (Country = "USA" AND City = "Portland") OR (Country = "Canada" AND City = "Vancouver");
    
-- 4. Show a list the Contact Name and Contact Title for all Suppliers with a SupplierID from 5 to 8 (inclusive) and sort in descending order by ContactName.
SELECT ContactName, ContactTitle
	FROM hwSuppliers
    WHERE SupplierID >= 5 AND SupplierID <= 8
    ORDER BY ContactName DESC;
    
-- 5. Show a product name and unit price of the least expensive Products (i.e. lowest unit price)? You MUST use a Sub Query.
SELECT ProductName, UnitPrice
	FROM hwProducts
    WHERE UnitPrice = (SELECT MIN(UnitPrice) FROM hwProducts)
    GROUP BY ProductName, UnitPrice;
    
-- 6. Display Order Count by their Ship Country for all except USA between May 4th and 10th 2015 whose Order Count is greater than 3.    
SELECT ShipCountry, COUNT(ShipCountry) AS 'Order Count'
	FROM hwOrders
    WHERE ShipCountry <> "USA" AND ShippedDate BETWEEN '2015/05/04' AND '2015/05/10'
    GROUP BY ShipCountry
    HAVING COUNT(ShipCountry) > 3;

-- 7. Show a list of all employees with their first name, last name and hiredate (formated to mm/dd/yyyy) who are NOT living in the USA and have been employed for at least 5 years.
SELECT FirstName, LastName, DATE_FORMAT(HireDate, "%m/%d/%Y") AS "Date"
    FROM hwEmployees
    WHERE Country <> "USA" AND HireDate <= date_sub(current_date(), interval 5 year);
    
-- 8. Show a list of Product Name and their 'Inventory Value' (Inventory Value = units in stock multiplied by their unit price) for products whose 'Inventory Value' is over 3000 but less than 4000.
SELECT ProductName, (UnitPrice * UnitsInStock) AS 'Inverntory Value'
	FROM hwProducts
    WHERE (UnitPrice * UnitsInStock) > 3000 AND (UnitPrice * UnitsInStock) < 4000;
    
-- 9. Show a list of Products' product Name, Unit in Stock and ReorderLevel level whose Product Name starts with 'S' that are currently in stock (i.e. at least one Unit in Stock) and inventory level is at or below the reorder level.
SELECT ProductName, UnitsInStock, ReorderLevel
	FROM hwProducts
    WHERE ProductName LIKE "S%" AND UnitsInStock > 0 AND UnitsInStock <= ReorderLevel;
    
-- 10. Show a Product Name, Unit Price for all products, whose Quantity Per Unit has/measure in 'box' that have been discontinued (i.e. discontinued = 1).
SELECT ProductName, UnitPrice, QuantityPerUnit, Discontinued
	FROM hwProducts
	WHERE QuantityPerUnit LIKE "%box%" AND Discontinued = 1;
    
-- 11. Show a list of Product Name and their TOTAL inventory value (inventory value = UnitsInStock * UnitPrice) for Supplier's Country from Japan.
SELECT ProductName, (UnitsInStock * UnitPrice) AS TOTAL
	FROM hwProducts P
    JOIN hwSuppliers S ON (P.SupplierID = S.SupplieriD)
	WHERE S.Country = 'Japan';
    
-- 12. Show a list country and their customer's count that is greater than 8.
SELECT Country, COUNT(CustomerID) AS 'Customer Count'
	FROM hwCustomers
    GROUP BY Country
    HAVING COUNT(CustomerID) > 8;
    
-- 13. Show a list of Orders' Ship Country, Ship City and their Order count for Ship Country 'Austria' and 'Argentina'.
SELECT ShipCountry, ShipCity, COUNT(OrderID) AS "Order count"
	FROM hwOrders
    GROUP BY ShipCountry, ShipCity
    HAVING ShipCountry = "Austria" OR ShipCountry = "Argentina";
    
-- 14. Show a list of Supplier's Company Name and Product's Product Name for supplier's country from Spain.
SELECT S.CompanyName, P.ProductName
	FROM hwSuppliers S
    JOIN hwProducts P ON (P.SupplierID = S.SupplieriD)
    WHERE S.Country = "Spain";
    
-- 15. What is the 'Average Unit Price' (rounded to two decimal places) of all the products whose ProductName ends with 'T'?
SELECT ROUND(AVG(UnitPrice),2)
	FROM hwProducts
    WHERE ProductName LIKE "%T";

-- 16. Show a list of employee's full name (i.e. firstname, lastname), title and their Order count for employees who has more than 120 orders.
SELECT CONCAT(E.FirstName, " ", E.LastName) AS "Full Name", E.Title, COUNT(O.OrderID) AS "Order Count"
	FROM hwEmployees E
    JOIN hwOrders O on (E.EmployeeID = O.EmployeeID)
    GROUP BY E.FirstName, E.LastName, E.Title
    HAVING COUNT(O.OrderID) > 120;
    
-- 17. Show a list customer's company Name and their country who has NO Orders on file (i.e. NULL Orders).
SELECT C.CompanyName, C.Country
	FROM hwCustomers C
	LEFT JOIN hwOrders O ON (C.CustomerID = O.CustomerID)
    WHERE O.CustomerID = NULL;
    
-- 18. Show a list of Category Name and Product Name for all products that are currently out of stock (i.e. UnitsInStock = 0).
SELECT C.CategoryName, P.ProductName
	FROM hwCategories C
    INNER JOIN hwProducts P ON (C.CategoryID = P.CategoryID)
    WHERE P.UnitsInStock = 0;
    
-- 19. Show a list of products' Product Name and Quantity Per Unit, which are measured in 'pkg' or 'pkgs' or 'jars' for a supplier’s country from Japan.
SELECT P.ProductName, P.QuantityPerUnit
	FROM hwProducts P
    INNER JOIN hwSuppliers S ON (P.SupplierID = S.SupplierID)
	WHERE (QuantityPerUnit LIKE "%pkg%" OR QuantityPerUnit LIKE "%jars%") AND S.Country = "Japan";

-- 20. Show a list of customer's company name, their Order’s ship name and total value of all their orders (rounded to 2 decimal places) for customer's from Mexico. (value of order = (UnitPrice multiplied by Quantity) less discount).
SELECT C.CompanyName, O.ShipName, ROUND((UnitPrice * Quantity) - Discount,2) AS Total
	FROM hwCustomers C 
    INNER JOIN hwOrders O ON (C.CustomerID = O.CustomerID)
    INNER JOIN hwOrderDetails D ON (O.OrderID = D.OrderID);
    
-- 21. Show a list of products' Product Name and suppliers' Region whose product name starts with 'L' and Region is NOT blank/empty.
SELECT P.ProductName, S.Region
	FROM hwProducts P
    INNER JOIN hwSuppliers S ON (P.SupplierID = S.SupplierID)
    WHERE P.ProductName LIKE "L%" AND S.Region <> "";

-- 22. Show a list of Order's Ship Country, Ship Name and Order Date (formatted as MonthName and Year, e.g. March 2015) for all Orders from 'Versailles' Ship City whose Customer's record doesn't exists in Customer table.
SELECT O.ShipCountry, O.ShipName, DATE_FORMAT(O.OrderDate, "%M %Y" ) AS "Date"
	FROM hwOrders O
    LEFT JOIN hwCustomers C ON (C.CustomerID = O.CustomerID)
    WHERE C.CustomerID = NULL AND O.ShipCity = 'Versailles';
    
-- 23. Show a list of products' Product Name and Units In Stock whose Product Name starts with 'F' and Rank them based on UnitsInStock from highest to lowest (i.e. highest UnitsInStock rank = 1, and so on). Display rank number as well.
SELECT ProductName, UnitsInStock,
	RANK () OVER ( 
		ORDER BY UnitsInStock DESC
	) ranking 
	FROM hwProducts
    WHERE ProductName LIKE "F%";
    
-- 24. Show a list of products' Product Name and Unit Price for ProductID from 1 to 5 (inclusive) and Rank them based on UnitPrice from lowest to highest. Display rank number as well.
SELECT ProductName, UnitPrice,
	RANK () OVER ( 
		ORDER BY UnitPrice
	) ranking 
	FROM hwProducts
    WHERE ProductID BETWEEN 1 AND 5;
    
-- 25. Show a list of employees' first name, last name, country and date of birth (formatted to mm/dd/yyyy) who were born after 1984 and Rank them by date of birth (oldest employee rank 1st, and so on) for EACH country, i.e. Rank number should reset/restart for EACH country.
SELECT FirstName, LastName, Country, DATE_FORMAT(BirthDate, "%m/%d/%Y"),
	RANK () OVER ( 
		PARTITION BY Country
		ORDER BY BirthDate
	) ranking 
	FROM hwEmployees
    WHERE BirthDate >= '1984/01/01';



