#include "roster.h"
#include <iostream>

Roster::Roster() {
	arrCount = 0;
}
Roster::~Roster() {
	for (int i = 0; i < arrCount; i++)
	{
		Student* student = classRosterArray[i];
		delete student;
	}

}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	classRosterArray[arrCount++] = student;
}
void Roster::remove(string studentID) {
	bool found = false;
	int i;
	for (i = 0; i < arrCount; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			classRosterArray[i]->setStudentID("0");
			break;
		}
	}
	if (found == false) {
		std::cout << "Student with this ID was not found." << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < arrCount; i++) {
		if (classRosterArray[i]->getStudentID() != "0") {
			classRosterArray[i]->print("StudentID");
			classRosterArray[i]->print("FirstName");
			classRosterArray[i]->print("LastName");
			classRosterArray[i]->print("Age");
			classRosterArray[i]->print("DaysToComplete");
			classRosterArray[i]->print("DegreeProgram");
		}
	}
}

//void Roster::printAll() {
//	for (int i = 0; i < arrCount; i++) {
//		int* dtc = (classRosterArray[i]->getDaysToComplete());
//		if (classRosterArray[i]->getStudentID() != "0") {
//			std::cout << classRosterArray[i]->getStudentID() << "\tFirst Name: " << classRosterArray[i]->getFirstName()
//				<< "\tLast Name: " << classRosterArray[i]->getLastName() << "\tAge: " << classRosterArray[i]->getAge()
//				<< "\tdaysInCourse: { " << *(dtc) << ", " << *(dtc + 1) << ", " << *(dtc + 2) << " }" << "\tDegree Program: ";
//			switch (classRosterArray[i]->getDegreeProgram()) {
//			case DegreeProgram::SECURITY:
//				cout << "Security" << endl;
//				break;
//			case DegreeProgram::NETWORK:
//				cout << "Network" << endl;
//				break;
//			case DegreeProgram::SOFTWARE:
//				cout << "Software" << endl;
//				break;
//			}
//		}
//	}
//}

void Roster::printAverageDaysInCourse(string studentID) {
	
	for (int i = 0; i < arrCount; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* dtc = (classRosterArray[i]->getDaysToComplete());
			int avgDays = (*(dtc) + *(dtc + 1) + *(dtc + 2)) / 3;
			std::cout << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ": " << avgDays << endl;
			break;
		}
	}
}
void Roster::printInvalidEmails() {
	for (int i = 0; i < arrCount; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find(" ") != string::npos || email.find("@") == string::npos || email.find(".") == string::npos) {
			std::cout << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < arrCount; i++) {
		if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
			cout << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " ";
			switch (degreeProgram) {
			case DegreeProgram::SECURITY:
				cout << "Security" << endl;
				break;
			case DegreeProgram::NETWORK:
				cout << "Network" << endl;
				break;
			case DegreeProgram::SOFTWARE:
				cout << "Software" << endl;
				break;
			}
		}
	}
}
string Roster::getStudentID(int i) {
	return classRosterArray[i]->getStudentID();
}
	