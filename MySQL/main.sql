-- SQL Test
/*
STARTS WITH 
*/

SELECT DISTINCT CITY FROM STATION WHERE  CITY LIKE "a%" OR CITY LIKE "e%" OR CITY LIKE "i%" OR CITY LIKE "o%" OR CITY LIKE  "u%";


/*
ENDS with 
*/

SELECT DISTINCT CITY FROM STATION WHERE  CITY LIKE "%a" OR CITY LIKE "%e" OR CITY LIKE "%i" OR CITY LIKE "%o" OR CITY LIKE  "%u";


/*
Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and u) as both their first and last characters. Your result cannot contain duplicates.
*/
SELECT DISTINCT CITY FROM STATION 
WHERE  (CITY LIKE "%a" OR CITY LIKE "%e" OR CITY LIKE "%i" OR CITY LIKE "%o" OR CITY LIKE  "%u")
AND
(CITY LIKE "a%" OR CITY LIKE "e%" OR CITY LIKE "i%" OR CITY LIKE "o%" OR CITY LIKE  "u%"); 




/*
Query the list of CITY names from STATION that do not start with vowels. Your result cannot contain duplicates.
*/

SELECT DISTINCT CITY FROM STATION WHERE (CITY NOT LIKE "%a" OR CITY NOT LIKE "%e" OR CITY NOT LIKE "%i" OR CITY NOT LIKE "%o" OR CITY NOT LIKE  "%u")

/*
Query the list of CITY names from STATION that do not start with vowels. Your result cannot contain duplicates.
*/
SELECT DISTINCT CITY FROM STATION WHERE  NOT (CITY  LIKE "a%" OR CITY  LIKE "e%" OR CITY LIKE "i%" OR CITY  LIKE "o%" OR CITY LIKE  "u%");

/*
Query the list of CITY names from STATION that do not end with vowels. Your result cannot contain duplicates.


*/
SELECT DISTINCT CITY FROM STATION WHERE NOT (CITY  LIKE "%a" OR CITY  LIKE "%e" OR CITY  LIKE "%i" OR CITY  LIKE "%o" OR CITY  LIKE  "%u");



/*
Query the list of CITY names from STATION that either do not start with vowels or do not end with vowels. Your result cannot contain duplicates.
*/
SELECT DISTINCT CITY FROM STATION WHERE NOT ( (CITY  LIKE "%a" OR CITY  LIKE "%e" OR CITY  LIKE "%i" OR CITY  LIKE "%o" OR CITY  LIKE  "%u") AND  (CITY  LIKE "a%" OR CITY  LIKE "e%" OR CITY  LIKE "i%" OR CITY  LIKE "o%" OR CITY  LIKE  "u%"));


/*
Query the list of CITY names from STATION that do not start with vowels and do not end with vowels. Your result cannot contain duplicates.
*/
SELECT DISTINCT CITY FROM STATION WHERE NOT ( (CITY  LIKE "%a" OR CITY  LIKE "%e" OR CITY  LIKE "%i" OR CITY  LIKE "%o" OR CITY  LIKE  "%u") OR  (CITY  LIKE "a%" OR CITY  LIKE "e%" OR CITY  LIKE "i%" OR CITY  LIKE "o%" OR CITY  LIKE  "u%"));


/*
Return names of students who have mark more than 75 and sort them based on first three characters and show them based on ID

*/
SELECT NAME FROM STUDENTS WHERE MARKS>75 ORDER BY SUBSTRING(NAME, -3), ID ASC;


/*Write a query that prints a list of employee names (i.e.: the name attribute) from the Employee table in alphabetical order.*/
SELECT NAME FROM EMPLOYEE ORDER BY NAME ASC;


/*
Write a query that prints a list of employee names (i.e.: the name attribute) for employees in Employee having a salary greater than  per month who have been employees for less than  months. Sort your result by ascending employee_id.*/
SELECT NAME FROM EMPLOYEE WHERE(SALARY > 2000    AND    MONTHS < 10) ORDER BY EMPLOYEE_ID ASC;