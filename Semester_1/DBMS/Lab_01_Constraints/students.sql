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

