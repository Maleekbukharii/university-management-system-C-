#include<iostream>
#include<string>
#include"Header.h"
#include<conio.h>
#include<windows.h>
#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
#include<sstream>
using namespace std;
void Person::setFName(string f) {
	this->fname = f;
}
void Person::setLName(string l) {
	this->lname = l;
}
void Person::setGender(string g) {
	this->gender = g;
}
void Person::setContact(string c) {
	this->contact = c;
}
string Person::getFName() {
	return fname;
}
string Person::getLName() {
	return lname;
}
string Person::getGender() {
	return gender;
}
string Person::getContact() {
	return contact;
}
vector<Attendance> readCSV() {
	ifstream file("Attendance.txt");
	vector<Attendance> users;

	try {
		if (!file.is_open()) {
			throw "Error opening file";
		}

		string line;
		while (getline(file, line)) {
			istringstream iss(line);
			string token;
			Attendance a;

			getline(iss, a.username, ',');
			getline(iss, a.password, ',');
			getline(iss, a.name, ',');

			while (getline(iss, token, ',')) {
				a.dates.push_back(token);
			}

			while (getline(iss, token, ',')) {
				a.attendance.push_back(stoi(token));
			}

			users.push_back(a);
		}

		file.close();
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}

	return users;
}
void writeCSV(const std::vector<Attendance>& users) {
	try {
		std::ofstream file("Marks.txt");

		if (!file) {
			throw "Error opening file";
		}

		for (const auto& user : users) {
			file << user.username << ',' << user.password << ',' << user.name;
			for (const auto& date : user.dates) {
				file << ',' << date;
			}
			for (const auto& attendance : user.attendance) {
				file << ',' << attendance;
			}
			file << endl;
		}

		file.close();
	}
	catch (const exception& e) {
		cerr << "Exception: " << e.what() << endl;
	}
}
void Person::display() {
	cout << "Name: " << getFName() << " " << getLName() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Contact Number: " << getContact() << endl;


}
string Person::operator-(string& u) {
	return u.erase(0, 5);
}
int Signin::check(string username, string pass) {
	ifstream fin;
	bool flag = 1;
	int tCount = 0, hCount = 0, aCount = 0, sCount = 0;
	string u, p, temp, temp1, temp2;
	try {
		fin.open("loginTeacher.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (; !fin.eof(); ++tCount) {
			getline(fin, u);
		}
		fin.close();

		fin.open("loginHOD.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (; !fin.eof(); ++hCount) {
			getline(fin, u);
		}
		fin.close();

		fin.open("loginAdmin.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (; !fin.eof(); ++aCount) {
			getline(fin, u);
		}
		fin.close();

		fin.open("loginStudent.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (; !fin.eof(); ++sCount) {
			getline(fin, u);
		}
		fin.close();

		fin.open("loginHOD.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (int i = 0; i < hCount; ++i) {

			getline(fin, u, ',');
			getline(fin, p, ',');
			getline(fin, temp1);
			int rsltU = u.compare(username);
			int rsltP = p.compare(pass);
			if (rsltU == 0 && rsltP == 0) {
				return 1;
			}
		}
		fin.close();

		fin.open("loginStudent.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (int i = 0; i < sCount; ++i) {

			getline(fin, u, ',');
			getline(fin, p, ',');
			getline(fin, temp1);
			int rsltU = u.compare(username);
			int rsltP = p.compare(pass);
			if (rsltU == 0 && rsltP == 0) {
				setUsername(u);
				setPass(p);
				return 2;
			}
		}
		fin.close();

		fin.open("loginTeacher.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (int i = 0; i < tCount; ++i) {

			getline(fin, u, ',');
			getline(fin, p, ',');
			getline(fin, temp1);
			int rsltU = u.compare(username);
			int rsltP = p.compare(pass);
			if (rsltU == 0 && rsltP == 0) {
				return 3;
			}
		}
		fin.close();

		fin.open("loginAdmin.txt");
		if (!fin.is_open()) {
			throw "Error opening file";
		}
		fin >> temp;
		fin.ignore();
		for (int i = 0; i < aCount; ++i) {

			getline(fin, u, ',');
			getline(fin, p, ',');
			getline(fin, temp1);
			int rsltU = u.compare(username);
			int rsltP = p.compare(pass);
			if (rsltU == 0 && rsltP == 0) {
				return 4;
			}
		}
		fin.close();

		system("cls");
		cout << "Incorrect Password or Username" << endl;
		Sleep(1500);
		display();
		return 0;
	}
	catch (exception& e) {
		cerr << "Exception : " << e.what() << endl;
		return 0;
	}
}
void Signin::display() {
	system("cls");
	cout << "Username:" << endl;
	cin >> username;
	cout << "Password:" << endl;
	cin >> pass;
	ofstream fout;
	fout.open("User.txt", ios::out);
	fout << username << ',' << pass;
	fout.close();
	Display d;
	d.check(username, pass);
}
void HOD::display() {
	cout << "Welcome HOD" << endl;
	cout << "1-TimeTable" << endl;
	cout << "2-Assign Marks" << endl;
	cout << "3-Assign Grades" << endl;
	cout << "4-View Students" << endl;
	cout << "5-View Teachers" << endl;
	cout << "6-View Attendence" << endl;
	cout << "7-Logout" << endl;
	int choice;
	try {
		cin >> choice;
		if (cin.fail()) {
			throw "Invalid input";
		}
		switch (choice) {
		case 1:
			timetable();
			break;
		case 2:
			assignMarks();
			break;
		case 3:
			assignGrade();
			break;
		case 4:
			viewStudents();
			break;
		case 5:
			viewTeachers();
			break;
		case 6:
			attendence();
			break;
		case 7:
			s1.display();
			break;
		default:
			cout << "Invalid Choice" << endl;
			Sleep(1000);
			display();
			break;
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
}
void Student::display() {
	system("cls");
	cout << "Welcome Student" << endl;
	cout << "1-View Attendance" << endl;
	cout << "2-View Marks" << endl;
	cout << "3-View Grades" << endl;
	cout << "4-View Registered Courses" << endl;
	cout << "5-View Fee Status" << endl;
	cout << "6-Logout" << endl;
	int choice;
	try {
		cin >> choice;
		if (cin.fail()) {
			throw "Invalid input";
		}
		switch (choice) {
		case 1:
			viewAttendence();
			break;
		case 2:
			viewMarks();
			break;
		case 3:
			viewGrade();
			break;
		case 4:
			viewCourses();
			break;
		case 5:
			viewFee();
			break;
		case 6:
			s2.getUsername();
			break;
		default:
			cout << "Invalid Choice" << endl;
			Sleep(1000);
			display();
			break;
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		display();
	}
}
void Teacher::display() {
	system("cls");
	cout << "Welcome Teacher" << endl;
	cout << "1-Timetable" << endl;
	cout << "2-Assign Marks" << endl;
	cout << "3-Assign Grades" << endl;
	cout << "4-View Students" << endl;
	cout << "5-View Attendence" << endl;
	cout << "6-Logout" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		teacherTimetable();
		break;
	case 2:
		assignMarks();
		break;
	case 3:
		assignGrade();
		break;
	case 4:
		viewStudents();
		break;
	case 5:
		attendence();
		break;
	case 6:
		s4.display();
		break;
	default:
		cout << "Invalid Choice" << endl;
		Sleep(1000);
		display();
		break; {
		}
	}
}
void Administrator::display() {
	system("cls");
	cout << "Welcome Administrator" << endl;
	cout << "1-Add Teacher" << endl;
	cout << "2-Add Student" << endl;
	cout << "3-Edit Student" << endl;
	cout << "4-Edit Teacher" << endl;
	cout << "5-View Students" << endl;
	cout << "6-View Teachers" << endl;
	cout << "7-Logout" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		addTeacher();
		break;
	case 2:
		addStudent();
		break;
	case 3:
		editStudent();
		break;
	case 4:
		editTeacher();
		break;
	case 5:
		viewStudents();
		break;
	case 6:
		viewTeachers();
		break;
	case 7:
		s3.display();
		break;
	default:
		cout << "Invalid Choice" << endl;
		Sleep(1000);
		display();
		break;
	}
}
void HOD::timetable() {
	try {
		ifstream fin("teachertimetable.txt");
		ifstream fin1("User.txt");
		string u, p;
		getline(fin1, u, ',');
		getline(fin1, p, ',');
		string line, temp1, temp2, temp;
		vector<vector<string>> timetable;
		int count = t.countTeachers() + countHOD();
		getline(fin, temp);
		for (int i = 0; i < count; ++i) {
			getline(fin, temp1, ',');
			getline(fin, temp2, ',');
			if (temp1 == u && temp2 == p) {
				getline(fin, line);
				stringstream ss(line);
				string cell;
				vector<string> row;
				while (getline(ss, cell, ','))
				{
					row.push_back(cell);
				}
				timetable.push_back(row);
				cout << "Monday   Tuesday   Wednesday   Thursday   Friday   Saturday" << endl;
				for (int i = 0; i < timetable.size(); i++)
				{
					cout << timetable[i][0] << endl;
					for (int j = 1; j < timetable[i].size(); j++)
					{
						cout << timetable[i][j] << "    ";
					}
					cout << endl;
				}
			}
			else
				getline(fin, temp);
		}
		fin.close();
		fin1.close();
	}
	catch (const ifstream::failure& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Error opening or reading file." << endl;
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Unknown error occurred." << endl;
	}
}
void updateCSV(const vector<Marks>& users) {
	ofstream file("Marks.txt");
	file << "temp" << endl;
	if (!file) {
		cout << "Error opening file." << endl;
		return;
	}
	for (const auto& user : users) {
		file << user.username << ',' << user.password << ',' << user.name << ',';
		for (size_t i = 0; i < user.subjects.size(); ++i) {
			file << user.subjects[i] << ',';
			if (i < user.marks.size()) {
				file << user.marks[i];
			}
			if (i != user.subjects.size() - 1) {
				file << ',';
			}
		}
		file << endl;
	}

	file.close();
}
void HOD::assignMarks() {
	try {
		ifstream file("Marks.txt");
		if (!file) {
			throw invalid_argument("Error opening file.");
		}
		vector<Marks> users;
		string line, temp;
		getline(file, temp);
		while (getline(file, line)) {
			stringstream ss(line);
			string token, num;
			Marks m;
			getline(ss, m.username, ',');
			getline(ss, m.password, ',');
			getline(ss, m.name, ',');
			getline(ss, num, ',');
			while (getline(ss, token, ',')) {
				m.subjects.push_back(token);
				getline(ss, token, ',');
				m.marks.push_back(stoi(token));
			}
			users.push_back(m);
		}
		file.close();
		for (const auto& Marks : users) {
			cout << "Username: " << Marks.username << endl;
			cout << "Password: " << Marks.password << endl;
			cout << "Name: " << Marks.name << endl;
			cout << "Subjects: ";
			for (size_t i = 0; i < Marks.subjects.size(); ++i) {
				cout << Marks.subjects[i] << " - " << Marks.marks[i];
				if (i != Marks.subjects.size() - 1) {
					cout << ", ";
				}
			}
			cout << endl << endl;
		}
		string usernameToUpdate;
		string subjectToUpdate;
		int newMarks;
		cout << "Enter username of the user: ";
		cin >> usernameToUpdate;
		cout << "Enter the subject to update: ";
		cin >> subjectToUpdate;
		cout << "Enter new marks: ";
		cin >> newMarks;
		bool foundUser = false;
		for (auto& user : users) {
			if (user.username == usernameToUpdate) {
				foundUser = true;
				bool foundSubject = false;
				for (size_t i = 0; i < user.subjects.size(); ++i) {
					if (user.subjects[i] == subjectToUpdate) {
						foundSubject = true;
						user.marks[i] = newMarks;
						break;
					}
				}
				if (!foundSubject) {
					throw invalid_argument("Subject not found for the user.");
				}
				break;
			}
		}
		if (!foundUser) {
			throw invalid_argument("User not found.");
		}
		updateCSV(users);
		cout << "Data updated successfully!" << endl;
	}
	catch (const ifstream::failure& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Error opening or reading file." << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Invalid argument." << endl;
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Unknown error occurred." << endl;
	}
}
void HOD::assignGrade() {
	cout << "HOD Grades assigning goes here" << endl;
}
void HOD::attendence() {
	cout << "HOD attendence goes here" << endl;
}
void HOD::viewStudents() {
	try {
		system("cls");
		int count = 0;
		Student s1;
		count = s1.countStudents();
		cout << count;
		Student* s = new Student[count];
		ifstream fin;
		fin.open("loginStudent.txt");
		if (!fin) {
			throw invalid_argument("Error opening file.");
		}
		string temp;
		fin >> temp;
		fin.ignore();
		for (int i = 0; i < count; ++i) {
			fin.ignore();
			string u, p, dep, roll, lname, fname, name, gender, contact, address, qual, blood, feeStatus, date;
			getline(fin, u, ',');
			getline(fin, p, ',');
			getline(fin, dep, ',');
			getline(fin, roll, ',');
			getline(fin, fname, ',');
			getline(fin, lname, ',');
			name = fname + " " + lname;
			getline(fin, gender, ',');
			getline(fin, contact, ',');
			getline(fin, address, ',');
			getline(fin, qual, ',');
			getline(fin, blood, ',');
			getline(fin, feeStatus, ',');
			getline(fin, date, ',');
			s[i] = Student(blood, feeStatus, dep, roll, address, qual, date, fname, lname, gender, contact, u, p);
			cout << s[i];
			fin.ignore();
		}
		cout << endl << "Press ESC to go back to Main Menu" << endl;
		int choice;
		choice = _getch();
		if (choice == 27) {
			display();
		}
	}
	catch (const ifstream::failure& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Error in opening or reading file." << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Invalid argument." << endl;
	}
	catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
		cout << "Unknown error occurred." << endl;
	}
}
void HOD::viewTeachers() {
	system("cls");
	int count = 0;
	Teacher t1;
	count = t1.countTeachers();
	cout << count;
	Teacher* t = new Teacher[count];
	ifstream fin;
	fin.open("loginTeacher.txt");
	string temp;
	fin >> temp;
	fin.ignore();
	for (int i = 0; i < count; ++i) {
		fin.ignore();
		string  p, tId, fname, lname, depName, gender, contact, address, qual, date, username;
		getline(fin, username, ',');
		getline(fin, p, ',');
		getline(fin, tId, ',');
		getline(fin, fname, ',');
		getline(fin, lname, ',');
		getline(fin, depName, ',');
		getline(fin, gender, ',');
		getline(fin, contact, ',');
		getline(fin, address, ',');
		getline(fin, qual, ',');
		getline(fin, date, ',');
		t[i] = Teacher(tId, depName, address, qual, date, fname, lname, gender, contact, username, p);
		cout << t[i];
	}
	cout << endl << "Press ESC to go back to Main Menu" << endl;
	int choice;
	choice = _getch();
	if (choice == 27) {
		display();
	}
}
void Student::viewAttendence() {
	cout << "Student attendence goes here" << endl;
}
void Student::viewMarks() {
	ifstream fin, fin1;

	string name;
	string Ccount, temp;

	fin.open("Marks.txt");
	fin1.open("User.txt");
	string u;
	string p;
	getline(fin1, u, ',');
	getline(fin1, p, ',');
	getline(fin, temp);
	string temp1, temp2;

	int count = countStudents();
	for (int j = 0; j < count; ++j) {
		getline(fin, temp1, ',');
		getline(fin, temp2, ',');
		if (temp1 == u && temp2 == p) {
			system("cls");
			getline(fin, name, ',');
			getline(fin, Ccount, ',');

			int Ccount1 = stoi(Ccount);
			string* courses = new string[Ccount1];
			for (int i = 0; i < Ccount1; i++) {
				getline(fin, courses[i], ',');
			}
			string* marks = new string[Ccount1];
			for (int i = 0; i < Ccount1; i++) {
				getline(fin, marks[i], ',');
			}
			cout << "Student Name: " << name << endl;
			cout << "Courses:   " << endl;
			for (int i = 0; i < Ccount1; i++) {
				cout << courses[i] << " " << marks[i] << endl;
			}

		}
		else
			getline(fin, temp);
	}
	cout << endl << "Press ESC to go back to Main Menu" << endl;
	int choice;
	choice = _getch();
	if (choice == 27) {
		display();
	}

}
void Student::viewGrade() {
	ifstream fin, fin1;

	string name;
	string Ccount, temp;

	fin.open("Marks.txt");
	fin1.open("User.txt");
	string u;
	string p;
	getline(fin1, u, ',');
	getline(fin1, p, ',');
	getline(fin, temp);
	string temp1, temp2;

	int count = countStudents();
	for (int j = 0; j < count; ++j) {
		getline(fin, temp1, ',');
		getline(fin, temp2, ',');
		if (temp1 == u && temp2 == p) {
			system("cls");
			getline(fin, name, ',');
			getline(fin, Ccount, ',');
			int Ccount1 = stoi(Ccount);
			string* courses = new string[Ccount1];
			for (int i = 0; i < Ccount1; i++) {
				getline(fin, courses[i], ',');
			}
			string* marks = new string[Ccount1];
			for (int i = 0; i < Ccount1; i++) {
				getline(fin, marks[i], ',');
			}
			cout << "Student Name: " << name << endl;
			cout << "Courses:   " << endl;
			for (int i = 0; i < Ccount1; i++) {
				cout << courses[i] << " " << marks[i] << endl;
			}

		}
		else
			getline(fin, temp);
	}
	cout << endl << "Press ESC to go back to Main Menu" << endl;
	int choice;
	choice = _getch();
	if (choice == 27) {
		display();
	}

}
void Student::viewCourses() {
	ifstream fin, fin1;

	string name;
	string Ccount, temp;

	fin.open("Marks.txt");
	fin1.open("User.txt");
	string u;
	string p;
	getline(fin1, u, ',');
	getline(fin1, p, ',');
	getline(fin, temp);
	string temp1, temp2;

	int count = countStudents();
	for (int j = 0; j < count; ++j) {
		getline(fin, temp1, ',');
		getline(fin, temp2, ',');
		if (temp1 == u && temp2 == p) {
			system("cls");
			getline(fin, name, ',');
			getline(fin, Ccount, ',');
			int Ccount1 = stoi(Ccount);
			string* courses = new string[Ccount1];
			for (int i = 0; i < Ccount1; i++) {
				getline(fin, courses[i], ',');
			}
			cout << "Student Name: " << name << endl;
			cout << "Courses:   " << endl;
			for (int i = 0; i < Ccount1; i++) {
				cout << "==========" << endl;
				cout << courses[i] << endl;
			}

		}
		else
			getline(fin, temp);
	}
	cout << endl << "Press ESC to go back to Main Menu" << endl;
	int choice;
	choice = _getch();
	if (choice == 27) {
		display();
	}

}
void Student::viewFee() {
	ifstream fin, fin1;
	fin.open("User.txt");

	fin1.open("loginStudent.txt");
	string u, p, temp, temp1, temp2, temp3, fee, temp4;
	getline(fin, u, ',');
	getline(fin, p, ',');
	getline(fin1, temp);
	for (int i = 0; i < countStudents() - 1; ++i) {
		getline(fin1, temp1, ',');
		getline(fin1, temp2, ',');
		if (u == temp1 && p == temp2) {
			for (int i = 0; i < 9; ++i) {
				getline(fin1, temp3, ',');
			}
			getline(fin1, fee, ',');
		}
		else
			getline(fin1, temp4);
	}
	cout << "Your Fee is: " << fee << endl;
	cout << endl << "Press ESC to go back to Main Menu" << endl;
	int choice;
	choice = _getch();
	if (choice == 27) {
		display();
	}
}
void Administrator::addTeacher() {
	system("cls");
	ifstream fin;
	ofstream fout;
	fout.open("loginTeacher.txt", ios::app);
	cout << "Enter Username of New Teacher: ";
	fin.open("loginTeacher.txt");
	string name;
	cin >> name;
	cout << "Enter Password of New Teacher: ";
	string pass;
	cin >> pass;
	cout << "Teacher Account Created Successfully!" << endl;
	string dep, lname, fname, gender, contact, address, qual, feeStatus, date;
	cout << "Enter Department Name: ";
	cin >> dep;
	Teacher t;
	string ID;
	if (t.countTeachers() < 10) {
		ID = "000" + to_string(t.countTeachers());
	}
	else if (t.countTeachers() < 100) {
		ID = "00" + to_string(t.countTeachers());
	}
	else if (t.countTeachers() < 1000) {
		ID = "0" + to_string(t.countTeachers());
	}
	else {
		ID = to_string(t.countTeachers());
	}
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Gender: ";
	cin >> gender;
	cout << "Enter Contact Number: ";
	cin >> contact;
	cin.ignore();
	cout << "Enter Address: ";
	getline(cin, address);
	cout << "Enter Qualification: ";
	getline(cin, qual);
	cout << "Enter Date of Registration: ";
	cin >> date;
	try {
		if (name.empty() || pass.empty() || dep.empty() || lname.empty() || fname.empty() || gender.empty() || contact.empty() || address.empty() || qual.empty() || date.empty()) {
			throw "Error: fields are empty.";
		}
		fout << name << "," << pass << "," << dep << "t-" << ID << "," << fname << "," << lname << "," << dep << ',' << gender << "," << contact << "," << address << "," << qual << "," << date << "," << endl;
		cout << "teacer account for " << name << " Created Successfully!" << endl;
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	fin.close();
	fout.close();
	fout.open("teachertimetable.txt", ios::app);
	fout << name << "," << pass << "," << fname + " " + lname << ",";
	fout.close();
	Sleep(1000);
	display();
}
void Administrator::addStudent() {
	ifstream fin;
	ofstream fout;
	fout.open("loginStudent.txt", ios::app);
	cout << "Enter Username of New Student: ";
	fin.open("loginStudent.txt");
	string name;
	cin >> name;
	cout << "Enter Password of New Student: ";
	string pass;
	cin >> pass;

	cout << "Student Account Created Successfully!" << endl;
	string dep, roll, lname, fname, gender, contact, address, qual, blood, feeStatus, date;
	cout << "Enter Department Name: ";
	cin >> dep;
	Student s;
	if (s.countStudents() < 10) {
		roll = "000" + to_string(s.countStudents() + 1);
	}
	else if (s.countStudents() < 100) {
		roll = "00" + to_string(s.countStudents() + 1);
	}
	else if (s.countStudents() < 1000) {
		roll = "0" + to_string(s.countStudents() + 1);
	}
	else {
		roll = to_string(s.countStudents() + 1);
	}
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Gender: ";
	cin >> gender;
	cout << "Enter Contact Number: ";
	cin >> contact;
	cin.ignore();
	cout << "Enter Address: ";
	getline(cin, address);
	cout << "Enter Qualification: ";
	getline(cin, qual);
	cout << "Enter Blood Group: ";
	cin >> blood;
	cout << "Enter Fee Status: ";
	cin >> feeStatus;
	cout << "Enter Date of Registration: ";
	cin >> date;
	cout << "Enter number of courses the student is studying: ";
	int num;
	cin >> num;
	string* names = new string[num];
	for (int i = 0; i < num; ++i) {
		cout << "Enter Course Name: ";
		cin >> names[i];
	}
	try {
		if (name.empty() || pass.empty() || dep.empty() || lname.empty() || fname.empty() || gender.empty() || contact.empty() || address.empty() || qual.empty() || blood.empty() || feeStatus.empty() || date.empty()) {
			throw "Error: fields are empty.";
		}
		fout << name << "," << pass << "," << dep << "," << roll << "," << fname << "," << lname << "," << gender << "," << contact << "," << address << "," << qual << "," << blood << "," << feeStatus << "," << date << "," << endl;
		cout << "Student Account for " << name << " Created Successfully!" << endl;
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	fout.close();
	fout.open("Marks.txt", ios::app);
	fout << name << "," << pass << "," << fname + " " + lname << "," << to_string(num) << ",";
	for (int i = 0; i < num; ++i) {
		fout << names[i] << "," << "0" << ",";
	}
	fout.close();
	Sleep(1000);
	display();
}
void Administrator::editStudent() {
	string line;
	cout << "Enter Roll Number of Student you want to edit(only number): " << endl;
	string roll;
	cin >> roll;
	Student s, * arr;
	int count;
	count = s.countStudents();
	arr = new Student[count];
	string u, p, r, check, temp, temp1, temp2;;
	ifstream fin;
	ofstream fout;
	bool flag = 0;
	int i = 0;
	fin.open("loginStudent.txt");
	fin >> temp;
	do {
		i++;
		getline(fin, temp1, ',');
		getline(fin, temp2, ',');
		string dep, rollNo;
		getline(fin, dep, ',');
		getline(fin, rollNo, ',');
		check = dep + "-" + rollNo;
		if (roll == rollNo) {
			flag = 1;
		}
		else {
			getline(fin, temp, '\n');
		}
	} while (flag == 0 || fin.eof());
	string lname, fname, name, gender, contact, address, qual, blood, feeStatus, date, dep;
	fin.close();
	fin.open("loginStudent.txt");
	if (flag) {
		fin >> temp;
		fin.ignore();
		for (int j = 0; j < count; ++j) {
			getline(fin, u, ',');
			getline(fin, p, ',');
			getline(fin, dep, ',');
			getline(fin, r, ',');
			getline(fin, fname, ',');
			getline(fin, lname, ',');
			getline(fin, gender, ',');
			getline(fin, contact, ',');
			getline(fin, address, ',');
			getline(fin, qual, ',');
			getline(fin, blood, ',');
			getline(fin, feeStatus, ',');
			getline(fin, date, ',');
			arr[j] = Student(blood, feeStatus, dep, r, address, qual, date, fname, lname, gender, contact, u, p);
		}
		cout << "Enter the attribute you want to change for " << check << ": " << endl;
		cout << "1-First Name" << endl << "2-Last Name" << endl << "3-Contact Number" << endl << "4-Address" << endl << "5-Fee Status" << endl;
		int choice;
		cin >> choice;
		string temp3, temp4, temp5, temp6, fname1, lname1, temp7, contact1, address1, temp8, temp9, feeStatus1; ;
		try {
			if (choice < 1 || choice > 5) {
				throw "Error: Invalid choice entered.";
			}
			switch (choice) {
			case 1:
				cout << "Enter New First Name: ";
				cin >> fname;
				arr[i - 1].setFName(fname);
				system("cls");
				cout << "First Name Updated Successfully!" << endl;
				Sleep(1500);
				break;
			case 2:
				cout << "Enter New Last Name: ";
				cin >> lname;
				arr[i - 1].setLName(lname);
				system("cls");
				cout << "Last Name Updated Successfully!" << endl;
				Sleep(1500);
				break;
			case 3:
				cout << "Enter New Contact Number: ";
				cin >> contact;
				arr[i - 1].setContact(contact);
				system("cls");
				cout << "Contact Number Updated Successfully!" << endl;
				Sleep(1500);
				break;
			case 4:
				cout << "Enter New Address: ";
				cin >> address;
				arr[i - 1].setAddress(address);
				system("cls");
				cout << "Address Updated Successfully!" << endl;
				Sleep(1500);
				break;
			case 5:
				cout << "Enter New Fee Status: ";
				cin >> feeStatus;
				arr[i - 1].setFeeStatus(feeStatus);
				system("cls");
				cout << "Fee Status Updated Successfully!" << endl;
				Sleep(1500);
				break;
			}
			fin.close();
			fout.open("loginStudent.txt", ios::out);

			fout << "Username,Password,DepartmentName,RollNumber,FirstName,LastName,Gender,ContactNumber,Address,Qualification,BloodGroup,FeeStatus,RegistrationDate," << endl;
			for (int j = 0; j < count; ++j) {
				fout << arr[j];
			}
			fout.close();
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
	else
		cout << "No Student Found with this Roll Number!" << endl;
	display();
}
void Administrator::editTeacher() {
	string line;
	cout << "Enter Teacher-id of Teacher you want to edit(only number): " << endl;
	string tid;
	cin >> tid;
	Teacher t, * arr;
	int count;
	count = t.countTeachers();
	arr = new Teacher[count];
	string  temp, temp1, temp2;;
	ifstream fin;
	ofstream fout;
	bool flag = 0;
	int i = 0;
	fin.open("loginTeacher.txt");
	fin >> temp;
	do {
		i++;
		getline(fin, temp1, ',');
		getline(fin, temp2, ',');
		string dep, teacherID;
		getline(fin, teacherID, ',');
		if (tid == teacherID) {
			flag = 1;
		}
		else
		{
			getline(fin, temp, '\n');
		}
	} while (flag == 0 || fin.eof());
	string tID, dep, address, qual, regDate, fname, lname, gender, contact, u, p;
	fin.close();
	fin.open("loginTeacher.txt");
	if (flag) {
		fin >> temp;
		fin.ignore();
		for (int j = 0; j < count; ++j) {
			getline(fin, u, ',');
			getline(fin, p, ',');
			getline(fin, tID, ',');
			getline(fin, fname, ',');
			getline(fin, lname, ',');
			getline(fin, dep, ',');
			getline(fin, gender, ',');
			getline(fin, contact, ',');
			getline(fin, address, ',');
			getline(fin, qual, ',');
			getline(fin, regDate, ',');
			arr[j] = Teacher(tID, dep, address, qual, regDate, fname, lname, gender, contact, u, p);
		}
		cout << "Enter the attribute you want to change for " << arr[i - 1].getTId() << ": " << endl;
		cout << "1-Address" << endl << "2-Contact" << endl << "3-Qualification" << endl << "4-Salary" << endl;
		int choice;
		cin >> choice;
		string temp3, temp4, temp5, temp6, fname1, lname1, temp7, contact1, address1, temp8, temp9, feeStatus1; ;
		switch (choice) {
		case 1:

			cout << "Enter New Address: ";
			cin >> address;
			arr[i - 1].setAddress(address);
			system("cls");
			cout << "Address Updated Successfully!" << endl;
			Sleep(1500);
			break;
		case 2:
			cout << "Enter New Contact: ";
			cin >> contact;
			arr[i - 1].setContact(contact);
			system("cls");
			cout << "Last Name Updated Successfully!" << endl;
			Sleep(1500);

			break;
		case 3:
			cout << "Enter New Qualification: ";
			cin >> qual;
			arr[i - 1].setQual(qual);
			system("cls");
			cout << "Contact Number Updated Successfully!" << endl;
			Sleep(1500);
			break;
		}
		fin.close();
		fout.open("loginTeacher.txt", ios::out);

		fout << "Username,Password,Teacherid,FirstName,LastName,DepartmentName,Gender,ContactNumber,Address,Qualification,RegistrationDate," << endl;
		for (int j = 0; j < count; ++j) {
			fout << arr[j];
		}
		fout.close();
	}
	else
		cout << "No Teacher Found with this ID!" << endl;
	display();
}
void Administrator::viewStudents() {
	system("cls");
	int count = 0;
	Student s1;
	count = s1.countStudents();
	cout << count;
	Student* s = new Student[count];
	ifstream fin;
	fin.open("loginStudent.txt");
	string temp;
	fin >> temp;
	fin.ignore();
	for (int i = 0; i < count; ++i) {
		fin.ignore();
		string u, p, dep, roll, lname, fname, name, gender, contact, address, qual, blood, feeStatus, date;
		getline(fin, u, ',');
		getline(fin, p, ',');
		getline(fin, dep, ',');
		getline(fin, roll, ',');
		getline(fin, fname, ',');
		getline(fin, lname, ',');
		name = fname + " " + lname;
		getline(fin, gender, ',');
		getline(fin, contact, ',');
		getline(fin, address, ',');
		getline(fin, qual, ',');
		getline(fin, blood, ',');
		getline(fin, feeStatus, ',');
		getline(fin, date, ',');
		s[i] = Student(blood, feeStatus, dep, roll, address, qual, date, fname, lname, gender, contact, u, p);
		cout << s[i];
		fin.ignore();
	}
	cout << endl << "Press ESC to go back to Main Menu" << endl;
	int choice;
	choice = _getch();
	if (choice == 27) {
		display();
	}
}
void Student::setDepName(string depName) {
	this->depName = depName;
}
string Student::getDepName() {
	return depName;
}
string Student::generateRoll() {
	int count;
	count = countStudents();
	ofstream fout;
	fout.open("loginStudent.txt", ios::app);
	string dep = getDepName();
	try {
		if (dep != "CS-" && dep != "EE-" && dep != "SE-" && dep != "BB-" && dep != "SS-") {
			throw "Error: Invalid department name.";
		}
		else {
			for (int i = 0; i < count;) {
				dep += to_string(count);
			}
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	return dep;
}
void Administrator::viewTeachers() {
	system("cls");
	int count = 0;
	Teacher t1;
	count = t1.countTeachers();
	cout << count;
	Teacher* t = new Teacher[count];
	ifstream fin;
	fin.open("loginTeacher.txt");
	string temp;
	fin >> temp;
	fin.ignore();
	for (int i = 0; i < count; ++i) {
		fin.ignore();
		string  p, tId, fname, lname, depName, gender, contact, address, qual, date, username;
		getline(fin, username, ',');
		getline(fin, p, ',');
		getline(fin, tId, ',');
		getline(fin, fname, ',');
		getline(fin, lname, ',');
		getline(fin, depName, ',');
		getline(fin, gender, ',');
		getline(fin, contact, ',');
		getline(fin, address, ',');
		getline(fin, qual, ',');
		getline(fin, date, ',');
		t[i] = Teacher(tId, depName, address, qual, date, fname, lname, gender, contact, username, p);
		cout << t[i];
	}
	cout << endl << "Press ESC to go back to Main Menu" << endl;
	int choice;
	choice = _getch();
	if (choice == 27) {
		display();
	}
}
void Teacher::teacherTimetable() {

	ifstream fin("teachertimetable.txt");
	ifstream fin1("User.txt");
	string u, p;
	getline(fin1, u, ',');
	getline(fin1, p, ',');
	string line, temp1, temp2, temp;
	vector<vector<string>> timetable;
	int count = countTeachers();
	getline(fin, temp);
	for (int i = 0; i < count; ++i) {
		getline(fin, temp1, ',');
		getline(fin, temp2, ',');
		if (temp1 == u && temp2 == p) {
			getline(fin, line);
			stringstream ss(line);
			string cell;
			vector<string> row;
			while (getline(ss, cell, ','))
			{
				row.push_back(cell);
			}
			timetable.push_back(row);
			for (int i = 0; i < timetable.size(); i++)
			{
				cout << timetable[i][0] << endl;
				for (int j = 1; j < timetable[i].size(); j++)
				{
					cout << timetable[i][j] << "    ";
				}
				cout << endl;

			}
		}
		else
			getline(fin, temp);
	}
	fin.close();
	fin1.close();

}
void Teacher::assignMarks() {
	system("cls");
	ifstream file("Marks.txt");
	if (!file) {
		try {
			throw "Error: Unable to open file.";
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}
	}
	vector<Marks> users;
	string line, temp;
	getline(file, temp);
	while (getline(file, line)) {
		stringstream ss(line);
		string token, num;
		Marks m;
		getline(ss, m.username, ',');
		getline(ss, m.password, ',');
		getline(ss, m.name, ',');
		while (getline(ss, token, ',')) {
			m.subjects.push_back(token);
			getline(ss, token, ',');
			m.marks.push_back(stoi(token));
		}
		users.push_back(m);
	}
	file.close();
	for (const auto& Marks : users) {
		cout << "Username: " << Marks.username << endl;
		cout << "Password: " << Marks.password << endl;
		cout << "Name: " << Marks.name << endl;
		cout << "Subjects: ";
		for (size_t i = 0; i < Marks.subjects.size(); ++i) {
			cout << Marks.subjects[i] << " - " << Marks.marks[i];
			if (i != Marks.subjects.size() - 1) {
				cout << ", ";
			}
		}
		cout << endl << endl;
	}
	string usernameToUpdate;
	string subjectToUpdate;
	int newMarks;
	cout << "Enter username of the user: ";
	cin >> usernameToUpdate;
	cout << "Enter the subject to update: ";
	cin >> subjectToUpdate;
	cout << "Enter new marks: ";
	cin >> newMarks;
	try {
		bool foundUser = false;
		for (auto& user : users) {
			if (user.username == usernameToUpdate) {
				foundUser = true;
				bool foundSubject = false;
				for (size_t i = 0; i < user.subjects.size(); ++i) {
					if (user.subjects[i] == subjectToUpdate) {
						foundSubject = true;
						user.marks[i] = newMarks;
						break;
					}
				}
				if (!foundSubject) {
					throw "Error: Subject not found for this user.";
				}
				break;
			}
		}
		if (!foundUser) {
			throw "Error: User not found.";
		}
		updateCSV(users);
		cout << "Data updated successfully!" << endl;
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	display();
}
void Teacher::assignGrade() {
	cout << "Teacher assign grade goes here" << endl;
}
void Teacher::attendence() {
	try {
		vector<Attendance> users = readCSV();
		string targetDate;
		cout << "Enter date to update attendance(YY/MM/DD): ";
		cin >> targetDate;
		bool foundDate = false;
		for (auto& user : users) {
			for (size_t i = 0; i < user.dates.size(); ++i) {
				if (user.dates[i] == targetDate) {
					cout << "Enter new attendance for " << user.name << " on " << targetDate << ": ";
					int newAttendance;
					cin >> newAttendance;
					user.attendance[i] = newAttendance;
					foundDate = true;
					break;
				}
			}
			if (foundDate) {
				break;
			}
		}
		if (!foundDate) {
			throw "Error: No attendance found.";
		}
		writeCSV(users);
		cout << "Data has been updated and written to the file." << endl;
		Sleep(1500);
		display();
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
}
void Teacher::viewStudents() {
	cout << "Teacher view students goes here" << endl;
}
void Teacher::viewTeachers() {
	cout << "view Teachers goes here" << endl;
}
string Student::getBlood() {
	return blood;
}
string Student::getFee() {
	return feeStatus;
}
string Student::getAddress() {
	return address;
}
string Student::getQual() {
	return qualification;
}
string Student::getRegDate() {
	return regDate;
}
string Student::getRollNo() {
	return rollNo;
}
ostream& operator<<(ostream& out, Student& s) {
	string name;
	name = s.getFName();
	name += " " + s.getLName();
	string dep, roll, gender, contact, address, qual, blood, feeStatus, date;
	dep = s.getDepName();
	roll = s.getRollNo();
	gender = s.getGender();
	contact = s.getContact();
	address = s.getAddress();
	qual = s.getQual();
	blood = s.getBlood();
	feeStatus = s.getFee();
	date = s.getRegDate();
	out << "=============================================================" << endl;
	out << "Name: " << name << endl << "Student-ID: " << dep << "-" << roll << endl << "Gender: " << gender << endl << "Contact: " << contact << endl <<
		"Address: " << address << endl << "Qualification: " << qual << endl << "Blood Group: " << blood << endl << "Fee Status: " << feeStatus << endl << "Registration Date: " << date << endl;
	out << "=============================================================== " << endl;
	return out;
}
ostream& operator<<(ostream& out, Teacher& t) {
	string name, username, temp;
	name = t.getFName();
	name += " " + t.getLName();
	string dep, tId, gender, contact, address, qual, date;
	username = t.getUsername();
	dep = t.getDepName();
	tId = t.countTeachers();
	gender = t.getGender();
	contact = t.getContact();
	address = t.getAddress();
	qual = t.getQual();
	date = t.getRegDate();
	out << "=============================================================" << endl;
	out << "Name: " << name << endl << "Gender: " << gender << endl << "Contact: " << contact << endl <<
		"Address: " << address << endl << "Qualification: " << qual << endl << "Username: " << username << endl;
	out << "=============================================================== " << endl;
	return out;
}
int Student::countStudents() {
	try {
		ifstream fin;
		string temp, temp1;
		int sCount = 0;
		fin.open("loginStudent.txt");
		if (!fin.is_open()) {
			throw "Error: File could not be opened.";
		}
		fin >> temp;
		fin.ignore();
		for (; !fin.eof(); ++sCount) {
			if (!fin.eof())
				getline(fin, temp1);
		}
		fin.close();
		return sCount - 1;
	}
	catch (const char* msg) {
		cerr << msg << endl;
		return 0;
	}
}
ofstream& operator<<(ofstream& out, Student& s) {
	string temp1, temp2, lname, fname, dep, roll, gender, contact, address, qual, blood, feeStatus, date;
	temp1 = s.getUsername();
	temp2 = s.getPassword();
	lname = s.getLName();
	fname = s.getFName();
	dep = s.getDepName();
	roll = s.getRollNo();
	gender = s.getGender();
	contact = s.getContact();
	address = s.getAddress();
	qual = s.getQual();
	blood = s.getBlood();
	feeStatus = s.getFee();
	date = s.getRegDate();

	out << temp1 << "," << temp2 << "," << dep << ","
		<< roll << "," << fname << "," << lname << "," << gender
		<< "," << contact << "," << address << "," << qual
		<< "," << blood << "," << feeStatus << "," << date << ",";
	return out;
}
ofstream& operator<<(ofstream& out, Teacher& t) {
	string temp1, temp2, lname, fname, dep, tid, gender, contact, address, qual, blood, feeStatus, date;
	temp1 = t.getUsername();
	temp2 = t.getPassword();
	lname = t.getLName();
	fname = t.getFName();
	dep = t.getDepName();
	tid = t.getTId();
	gender = t.getGender();
	contact = t.getContact();
	address = t.getAddress();
	qual = t.getQual();
	date = t.getRegDate();

	out << temp1 << "," << temp2 << "," << tid << ","
		<< fname << "," << lname << "," << dep << ',' << gender
		<< "," << contact << "," << address << "," << qual
		<< "," << date << ",";
	return out;
}
string Signin::getUsername() {
	return username;
}
string Signin::getPass() {
	return pass;
}
int Teacher::countTeachers() {
	try {
		ifstream fin;
		string temp, temp1;
		int tCount = 0;
		fin.open("loginTeacher.txt");
		if (!fin.is_open()) {
			throw "Error: File couldn't be opened.";
		}
		fin >> temp;
		fin.ignore();
		for (; !fin.eof(); ) {
			if (!fin.eof()) {
				getline(fin, temp1);
				tCount++;
			}
		}
		fin.close();
		return tCount - 1;
	}
	catch (const char* msg) {
		cerr << msg << endl;
		return 0;
	}
}
void Display::check(string username, string pass) {

	int num;
	num = Signin::check(username, pass);
	switch (num) {

	case 1:
		p[0]->display();
		break;
	case 2:
		p[1]->display();
		break;
	case 3:
		p[2]->display();
		break;
	case 4:
		p[3]->display();
		break;
	}
}
string Teacher::getAddress() {
	return address;
}
string Teacher::getQual() {
	return qualification;
}
string Teacher::getTId() {
	return tId;
}
string Teacher::getDepName() {
	return depName;
}
string Teacher::getRegDate() {
	return regDate;
}
string Teacher::getUsername() {
	return username;
}
string Student::getUsername() {
	return username;
}
string Student::getPassword() {
	return password;
}
string Teacher::getPassword() {
	return password;
}
void Student::setFeeStatus(string feeStatus) {
	this->feeStatus = feeStatus;
}
void Student::setAddress(string address) {
	this->address = address;
}
void Teacher::setAddress(string address) {
	this->address = address;
}
void Teacher::setQual(string qualification) {
	this->qualification = qualification;
}
void Student::setUsername(string u) {
	this->username = u;
}
void Student::setPassword(string p) {
	this->password = p;
}
void Signin::setUsername(string u) {
	this->username = u;
}
void Signin::setPass(string p) {
	this->pass = p;
}
int HOD::countHOD() {
	try {
		ifstream fin;
		string temp, temp1;
		int hCount = 0;
		fin.open("loginHOD.txt");
		if (!fin.is_open()) {
			throw "Error: File could not be opened.";
		}
		fin >> temp;
		fin.ignore();
		for (; !fin.eof(); ) {
			if (!fin.eof()) {
				getline(fin, temp1);
				hCount++;
			}
		}
		fin.close();
		return hCount - 1;
	}
	catch (const char* msg) {
		cerr << msg << endl;
		return 0;
	}
}