
-- DAY 02 - Department Table


CREATE TABLE department (
    dept_id CHAR(10) PRIMARY KEY,
    dept_name VARCHAR2(25) UNIQUE NOT NULL,
    hod_name VARCHAR2(10),
    office_location VARCHAR2(25),
    contact_number CHAR(12)
);

INSERT INTO department
VALUES ('D001', 'Computer Science', 'Dr Ahammed', 'Block A', '8075791489');

INSERT INTO department
VALUES ('D010', 'Mathematics', 'Dr Aaliya', 'Block B', '8075791489');

SELECT * FROM department;


-- DAY 02 - Students Table


CREATE TABLE students (
    student_id CHAR(10) CONSTRAINT pk_students PRIMARY KEY,
    student_name VARCHAR2(30) NOT NULL,
    dob DATE,
    gender CHAR(1)
        CONSTRAINT chk_gender
        CHECK (gender IN ('M', 'F')),
    email_id VARCHAR2(50)
        CONSTRAINT uq_email UNIQUE,
    dept_id CHAR(10),
    admission_date DATE,
    cgpa NUMBER(3,2)
        CONSTRAINT chk_cgpa
        CHECK (cgpa BETWEEN 0 AND 10)
);