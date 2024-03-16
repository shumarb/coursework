/******************************************************************************/
/* Fabian Pascal                                                              */
/* Indicate your student number here: A0149874L                               */
/******************************************************************************/
 SELECT per.empid, per.lname 
 FROM employee per, payroll pay
 WHERE per.empid = pay.empid 
 AND pay.salary = 189170;
 
/******************************************************************************/
/* Answer Question 1.a below                                                  */
/******************************************************************************/
SELECT per.empid, per.lname
FROM employee per
FULL OUTER JOIN payroll pay
ON per.empid = pay.empid
WHERE pay.salary = 189170
AND per.empid IS NOT NULL;
	

-- Indicate the average measured times for 1000 executions for the query.
-- (replace <time> with the average time reported by test function).

-- Average Planning 0.07 ms
-- Average Execution 3.03 ms

/******************************************************************************/
/* Answer Question 1.b below                                                  */
/******************************************************************************/
SELECT per.empid, per.lname
FROM employee per
WHERE EXISTS (
	SELECT *
	FROM payroll pay
	WHERE pay.empid = per.empid
	AND pay.salary = 189170
); 

-- Indicate the average measured times for 1000 executions for the query.
-- (replace <time> with the average time reported by test function).

-- Average Planning 0.07 ms
-- Average Execution 2.89 ms

/******************************************************************************/
/* Answer Question 1.c below                                                  */
/******************************************************************************/
SELECT per.empid, per.lname
FROM employee per
WHERE per.empid IN (
	SELECT pay.empid
	FROM payroll pay
	WHERE pay.salary = 189170
);

-- Indicate the average measured times for 1000 executions for the query.
-- (replace <time> with the average time reported by test function).

-- Average Planning 0.08 ms
-- Average Execution 3.00 ms

/******************************************************************************/
/* Answer Question 1.d below                                                  */
/******************************************************************************/
SELECT per.empid, per.lname
FROM employee per,
(SELECT *
FROM payroll pay WHERE pay.salary = 189170) AS second_query
WHERE per.empid = second_query.empid;


-- Indicate the average measured time for 1000 executions for the query.
-- (replace <time> with the average time reported by test function).

-- Average Planning 0.07 ms
-- Average Execution 3.01 ms

/******************************************************************************/
/* Answer Question 1.e below                                                  */
/*****************************************************************************/
SELECT per.empid, per.lname
FROM employee per
WHERE NOT EXISTS (
	SELECT *
	FROM payroll pay
	WHERE pay.empid = per.empid
	AND pay.salary <> 189170
); 

-- Indicate the average measured times for 1000 executions for the query.
-- (replace <time> with the average time reported by test function).

-- Average Planning 0.08 ms
-- Average Execution 6.05 ms

/******************************************************************************/
/* Answer Question 2 below (new query)                                        */
/******************************************************************************/
SELECT DISTINCT per.empid, per.lname
FROM employee per
CROSS JOIN payroll pay
WHERE NOT EXISTS (
	SELECT *
	FROM payroll pay
	WHERE pay.empid = per.empid
	AND pay.salary <> 189170
	AND pay.salary >= 0
	AND pay.bonus >= 0
	AND pay.empid IS NOT NULL
	AND pay.bonus IS NOT NULL
	AND pay.salary IS NOT NULL
	AND per.empid IS NOT NULL
	AND per.lname IS NOT NULL
	AND per.fname IS NOT NULL
	AND per.address IS NOT NULL
	AND per.city IS NOT NULL
	AND per.state IS NOT NULL
	AND per.zip IS NOT NULL
	AND CHAR_LENGTH(per.empid) <= 9
	AND CHAR_LENGTH(per.lname) <= 15
	AND CHAR_LENGTH(per.fname) <= 12
	AND CHAR_LENGTH(per.address) <= 20
	AND CHAR_LENGTH(per.city) <= 20
	AND CHAR_LENGTH(per.state) <=2
	AND CHAR_LENGTH(per.zip) <= 5
	AND CHAR_LENGTH(pay.empid) <= 9
);

-- Indicate the average measured time for 1000 executions for the query.
-- (replace <time> with the average time reported by test function).

-- Average Planning 0.15 ms
-- Average Execution 362.13 ms

/******************************************************************************/
/* Answer Question 3 below (constraints or indexes)                           */
/******************************************************************************/
ALTER TABLE employee ADD PRIMARY KEY(empid);
ALTER TABLE payroll ADD PRIMARY KEY (empid);
CREATE INDEX payroll_salary_index ON payroll (salary);

-- Indicate the new average measured times for 1000 executions for each of the 
-- five queries. 
-- (replace <time> with the average time reported by test function).

-- Q1.a 
-- Average Planning 0.10 ms
-- Average Execution 0.05 ms

-- Q1.b 
-- Average Planning 0.10 ms
-- Average Execution 0.04 ms

-- Q1.c 
-- Average Planning 0.11 ms
-- Average Execution 0.05 ms

-- Q1.d 
-- Average Planning 0.10 ms
-- Average Execution 0.05 ms

-- Q1.e 
-- Average Planning 0.14 ms
-- Average Execution 6.13 ms



