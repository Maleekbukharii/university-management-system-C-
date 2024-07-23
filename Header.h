#pragma once
#include<iostream>
#include<stdexcept>
#include<fstream>
#include<vector>
using namespace std;

class Person;
class Signin;
class HOD;
class Teacher;
class Student;
class Administrator;


class Person {
	string fname;
	string lname;
	string gender;
	string contact;
public:
	Person() {};
	Person(string fname, string lname, string gender, string contact) {
		this->fname = fname;
		this->lname = lname;
		this->gender = gender;
		this->contact = contact;
	}
	void setFName(string);
	void setLName(string);
	void setGender(string);
	void setContact(string);
	string getFName();
	string getLName();
	string getGender();
	string getContact();
	virtual void display();
	string operator -(string&);


};
class Signin {
	string username;
	string pass;
	ifstream fin;
	ofstream fout;

public:
	Signin() {}
	Signin(string username, string pass) {
		this->username = username;
		this->pass = pass;
	}
	string getUsername();
	string getPass();
	void setUsername(string);
	void setPass(string);
	int check(string, string);
	void display();


};
class Marks {
public:
	string username;
	string password;
	string name;
	vector<string> subjects;
	vector<int> marks;

};
class Attendance {
public:
	string username;
	string password;
	string name;
	vector<std::string> dates;
	vector<int> attendance;
};


class Student :public Person, Signin {
	string username;
	string password;
	string rollNo;
	string blood;
	string feeStatus;
	string depName;
	string address;
	string qualification;
	string regDate;
	Signin s2;
	Marks m;
public:
	Student() {
		rollNo = " ";
		blood = " ";
		feeStatus = " ";
		depName = " ";
		address = " ";
		qualification = " ";
		regDate = " ";
	}
	Student(string blood, string feeStatus, string depName, string roll, string address, string qualification, string regDate,
		string fname, string lname, string gender, string contact, string username, string password) :Person(fname, lname, gender, contact) {
		this->blood = blood;
		this->feeStatus = feeStatus;
		this->depName = depName;
		this->address = address;
		this->qualification = qualification;
		this->regDate = regDate;
		this->rollNo = roll;
		this->username = username;
		this->password = password;

	}
	Student(Marks m) {
		this->m = m;
	}
	void setDepName(string depName);
	void setFeeStatus(string feeStatus);
	void setAddress(string address);
	void setUsername(string username);
	void setPassword(string password);
	string getUsername();
	string getPassword();
	string getDepName();
	string getRollNo();
	string getBlood();
	string getFee();
	string getQual();
	string getRegDate();
	string generateRoll();
	string getAddress();
	int countStudents();
	void viewFee();
	void viewAttendence();
	void viewMarks();
	void viewGrade();
	void viewCourses();
	virtual void display();
	friend ostream& operator<<(ostream&, Student&);
	friend ofstream& operator<<(ofstream&, Student&);

};
class Teacher :public Person, Marks {
	Signin s4;
	string username;
	string password;
	string tId;
	string depName;
	string address;
	string qualification;
	string regDate;


public:
	Teacher() {}
	Teacher(string tId, string depName, string address, string qualification, string regDate, string fname, string lname, string gender, string contact, string username, string password) : Person(fname, lname, gender, contact) {
		this->tId = tId;
		this->depName = depName;
		this->address = address;
		this->qualification = qualification;
		this->regDate = regDate;
		this->username = username;
		this->password = password;
	}
	string getTId();
	string getDepName();
	string getAddress();
	string getQual();
	string getRegDate();
	//string generateTId();
	string getUsername();
	string getPassword();
	void setAddress(string address);
	void setQual(string qual);
	void teacherTimetable();
	void assignMarks();
	void assignGrade();
	void attendence();
	void viewStudents();
	void viewTeachers();
	virtual void display();
	friend ostream& operator<<(ostream&, Teacher&);
	friend ofstream& operator<<(ofstream&, Teacher&);
	int countTeachers();
};
class Administrator :public Person {
	Signin s3;
	Teacher t;
public:
	void addTeacher();
	void addStudent();
	void editStudent();
	void editTeacher();
	void viewStudents();
	void viewTeachers();
	virtual void display();
};

class HOD :public Person {
	Signin s1;
	Teacher t;
public:
	void timetable();
	void assignMarks();
	void assignGrade();
	void attendence();
	void viewStudents();
	void viewTeachers();
	virtual void display();
	int countHOD();
};

class Display :public Signin {
	Person* p[4] = { new HOD, new Student, new Teacher, new Administrator };
public:
	void check(string, string);
	friend void HOD::display();
	friend void Student::display();
	friend void Teacher::display();
	friend void Administrator::display();
};



