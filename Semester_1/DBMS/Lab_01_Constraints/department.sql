CREATE TABLE department (
    dept_id CHAR(10) PRIMARY KEY,
    dept_name VARCHAR2(25) UNIQUE NOT NULL,
    hod_name VARCHAR2(30),
    office_location VARCHAR2(25),
    contact_number CHAR(12)
);

INSERT INTO department
VALUES ('D001', 'Computer Science', 'Dr Ahammed', 'Block A', '8075791489');

INSERT INTO department
VALUES ('D010', 'Mathematics', 'Dr Aaliya', 'Block B', '8075791489');

SELECT * FROM department;