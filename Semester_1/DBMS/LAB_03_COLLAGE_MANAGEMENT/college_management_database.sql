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

create table result
(
	result_id varchar2(10) primary key,
	enroll_id varchar2(10),
	internal_mks number(2,0) check(internal_mks between 0 and 50),
	external_mks number(2,0) check(external_mks between 0 and 50),
	total_mks number(3),
   	grade char(1) check (grade in ('A', 'B', 'C', 'D', 'F')),
    	result_status varchar2(4) check (result_status in ('PASS', 'FAIL')),
    	constraint fk_result_enroll foreign key(enroll_id) references enroll(enroll_id)
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

insert into student values('S01','Kiran','20-jan-2000','M','123908','kiran@gmail','D03','10-june-2024','7');
insert into student values('S02','Megha','25-feb-2001','F','67890','megha@gmail','D01','10-june-2024','9');
insert into student values('S03','Mike','12-mar-2000','M','123909','mike@gmail','D05','11-june-2024','8');
insert into student values('S04','Sophia','09-oct-2000','F','676091','sophia@gmail','D02','10-june-2024','9');

insert into faculty values('F01','Abin','PhD','Proffesor','06-july-2020','40000','abin@gmail','D02');
insert into faculty values('F02','Mary','PG','Asst.Proffesor','10-july-2022','20000','mary@gmail','D03');
insert into faculty values('F03','Aksa','PhD','lecturer','01-aug-2020','25000','aksa@gmail','D01');

insert into course values('C01','BCA','5','4','D02','F01');
insert into course values('C02','BCom','3','5','D05','F03');
insert into course values('C03','Maths','5','7','D03','F02');

insert into enroll values('E01','S02','C03','05-jun-2020','2020');
insert into enroll values('E02','S04','C01','10-jun-2021','2021');
insert into enroll values('E03','S01','C02','01-jun-2022','2022');

insert into result values('R01','E02','30','45','75','C','PASS');
insert into result values('R02','E03','45','47','93','A','PASS');
insert into result values('R03','E01','10','15','25','F','FAIL');


insert into event values
('EV01','Tech Fest','15-aug-2024','Auditorium','F01',80,200);

insert into event values
('EV02','Literary Meet','20-jan-2024','Seminar Hall','F02',70,100);

insert into event values
('EV03','Math Quiz','25-feb-2024','Lab 1','F03',50,50);

insert into event values
('EV04','Social Expo','11-oct-2024','Conference Hall','F01',60,50);

insert into event values
('EV05','Commerce Fair','05-dec-2024','Main Block','F03',75,150);



insert into event_regn values
('RE01','EV01','S01','01-feb-2024','registered');

insert into event_regn values
('RE02','EV02','S02','02-jan-2024','attended');

insert into event_regn values
('RE03','EV03','S04','03-jan-2024','registered');

insert into event_regn values
('RE04','EV04','S03','04-dec-2024','absent');

insert into event_regn values
('RE05','EV05','S03','05-mar-2024','attended');





insert into dept values('D06','Computer Science','Dr. Anil Kumar','Carmel Block',8075791493);
insert into dept values('D07','Science','Ahammed','A Block',8075791666);
INSERT INTO dept
(dept_id, dept_name, hod_name, office_location, contact_number)
VALUES
('D08', 'Physics', 'Ahad', 'P Block', '9074084738');
insert into dept values('&dept_id','&dept_name','&hod_name','&office_location',&contact_number);






















