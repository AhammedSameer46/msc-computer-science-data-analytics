drop table event_regn;
drop table event;
drop table result;
drop table enroll;
drop table course;
drop table faculty;
drop table student;
drop table dept;

create table dept
(
 	dept_id varchar2(10) primary key, 
	dept_name varchar2(20) unique not null,
	hod_name varchar2(20),
	office_location varchar2(20),
	contact_number char(10)
);

create table student
(
 	stud_id varchar2(10) primary key, 
	stud_name varchar2(20),
	dob date,
	gender char(1) check(gender in ('M','F')),
	mobile char(10),
	email_id varchar2(25),
	dept_id varchar2(10),
	admission_date date,
	cgpa number(4,2) check(cgpa between 0 and 10),
	constraint fk_stud_dept foreign key(dept_id) references dept(dept_id)
);

create table faculty
(
	faculty_id varchar2(10) primary key,
	faculty_name varchar2(30),
	qualification varchar2(30),
	designation varchar2(20),
	joining_date date,
	salary number(10,2) check(salary>0),
	email_id varchar(20) unique,
	dept_id varchar2(10),
	constraint fk_fact_dept foreign key(dept_id) references dept(dept_id)
);

create table course
(
	course_code varchar2(10) primary key,
	course_name varchar2(30),
	credits number(2,0) check(credits between 1 and 6),
	semester number(1,0) check(semester between 1 and 8),
	dept_id varchar2(10),
	faculty_id varchar2(10),
	constraint fk_course_dept foreign key(dept_id) references dept(dept_id),
	constraint fk_course_faculty foreign key(faculty_id) references faculty(faculty_id)
);


create table enroll
(
	enroll_id varchar2(10) primary key,
	stud_id varchar2(10),
	course_code varchar2(10),
	Enrollment_Date date default sysdate,
	academic_year varchar2(9),
	constraint unique_enrollment unique (stud_id, course_code),
	constraint fk_enroll_stud foreign key(stud_id) references student(stud_id),
	constraint fk_enroll_course foreign key(course_code) references course(course_code)
);

create table event
(
	event_id varchar2(10) primary key,
	event_name varchar2(20),
	event_date date,
	venue varchar2(20),
	faculty_id varchar2(10),
	max_participants number(2,0) check(max_participants > 0),
	registration_fee number(10,2) check(registration_fee>=0),
    	constraint fk_event_faculty foreign key(faculty_id) references faculty(faculty_id)
);

create table event_regn
(
	registration_id varchar2(10) primary key,
	event_id varchar2(10),
	stud_id varchar2(10),
	registration_date date default sysdate,
	participation_status varchar2(15) check (participation_status in ('registered', 'absent', 'attended')),
    	constraint fk_eventreg_event foreign key(event_id) references event(event_id),
	constraint fk_eventreg_stud foreign key(stud_id) references student(stud_id)
);

insert into dept values('D01','English','abc','Kakkanad',1234567);
insert into dept values('D02','Computer science','def','Kalamassery',5613312);
insert into dept values('D03','Mathematics','ghi','Kakkanad',789456);
insert into dept values('D04','Social Science','jkl','Kalamassery',1254632);
insert into dept values('D05','Commerce','mno','Kalamassery',987456);

/* STUDENT */

insert into student values
('S01','Ahammed',to_date('15-06-2005','DD-MM-YYYY'),'M','9876543210','ahammed@gmail.com','D02',to_date('01-08-2023','DD-MM-YYYY'),8.75);

insert into student values
('S02','Anjali',to_date('21-09-2004','DD-MM-YYYY'),'F','9876543211','anjali@gmail.com','D01',to_date('01-08-2023','DD-MM-YYYY'),9.10);

insert into student values
('S03','Rahul',to_date('11-03-2005','DD-MM-YYYY'),'M','9876543212','rahul@gmail.com','D02',to_date('01-08-2023','DD-MM-YYYY'),8.40);

insert into student values
('S04','Neha',to_date('18-12-2004','DD-MM-YYYY'),'F','9876543213','neha@gmail.com','D03',to_date('01-08-2023','DD-MM-YYYY'),9.20);

insert into student values
('S05','Arun',to_date('08-02-2005','DD-MM-YYYY'),'M','9876543214','arun@gmail.com','D05',to_date('01-08-2023','DD-MM-YYYY'),7.95);


/* FACULTY */

insert into faculty values
('F01','Dr. Thomas','PhD','Professor',to_date('15-06-2015','DD-MM-YYYY'),85000,'thomas@gmail.com','D02');

insert into faculty values
('F02','Dr. Meera','PhD','Associate Professor',to_date('20-05-2016','DD-MM-YYYY'),78000,'meera@gmail.com','D01');

insert into faculty values
('F03','Dr. Rakesh','PhD','Assistant Professor',to_date('10-01-2018','DD-MM-YYYY'),65000,'rakesh@gmail.com','D03');

insert into faculty values
('F04','Dr. Joseph','MPhil','Assistant Professor',to_date('05-07-2019','DD-MM-YYYY'),60000,'joseph@gmail.com','D04');

insert into faculty values
('F05','Dr. Priya','PhD','Professor',to_date('01-02-2014','DD-MM-YYYY'),90000,'priya@gmail.com','D05');


/* COURSE */

insert into course values
('C01','Database Systems',4,3,'D02','F01');

insert into course values
('C02','Operating Systems',4,4,'D02','F01');

insert into course values
('C03','English Literature',3,2,'D01','F02');

insert into course values
('C04','Linear Algebra',4,1,'D03','F03');

insert into course values
('C05','Financial Accounting',4,3,'D05','F05');


/* ENROLL */

insert into enroll values
('E01','S01','C01',to_date('10-07-2024','DD-MM-YYYY'),'2024-2025');

insert into enroll values
('E02','S03','C02',to_date('10-07-2024','DD-MM-YYYY'),'2024-2025');

insert into enroll values
('E03','S02','C03',to_date('10-07-2024','DD-MM-YYYY'),'2024-2025');

insert into enroll values
('E04','S04','C04',to_date('10-07-2024','DD-MM-YYYY'),'2024-2025');

insert into enroll values
('E05','S05','C05',to_date('10-07-2024','DD-MM-YYYY'),'2024-2025');


/* EVENT */

insert into event values
('EV01','Tech Fest',to_date('15-09-2024','DD-MM-YYYY'),'Auditorium','F01',100,200);

insert into event values
('EV02','Literary Meet',to_date('20-09-2024','DD-MM-YYYY'),'Seminar Hall','F02',80,100);

insert into event values
('EV03','Math Quiz',to_date('25-09-2024','DD-MM-YYYY'),'Lab 1','F03',50,50);

insert into event values
('EV04','Social Expo',to_date('30-09-2024','DD-MM-YYYY'),'Conference Hall','F04',60,0);

insert into event values
('EV05','Commerce Fair',to_date('05-10-2024','DD-MM-YYYY'),'Main Block','F05',75,150);


/* EVENT_REGN */

insert into event_regn values
('R01','EV01','S01',to_date('01-09-2024','DD-MM-YYYY'),'registered');

insert into event_regn values
('R02','EV02','S02',to_date('02-09-2024','DD-MM-YYYY'),'attended');

insert into event_regn values
('R03','EV03','S04',to_date('03-09-2024','DD-MM-YYYY'),'registered');

insert into event_regn values
('R04','EV04','S03',to_date('04-09-2024','DD-MM-YYYY'),'absent');

insert into event_regn values
('R05','EV05','S05',to_date('05-09-2024','DD-MM-YYYY'),'attended');






