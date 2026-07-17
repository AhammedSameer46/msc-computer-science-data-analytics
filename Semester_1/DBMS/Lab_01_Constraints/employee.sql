CREATE TABLE employee (
    empid VARCHAR2(5) CONSTRAINT emp_pk PRIMARY KEY,
    empname VARCHAR2(10) NOT NULL,
    adhaarno VARCHAR2(15) UNIQUE,
    dob DATE DEFAULT '01-MAR-2000',
    salary NUMBER(10,2) CHECK (salary > 10000)
);

INSERT INTO employee
VALUES ('A001', 'abc', '123456789012', '24-SEP-2004', 100001);

INSERT INTO employee (empid, empname, salary)
VALUES ('B002', 'Ahad', 1010100);

SELECT * FROM employee;