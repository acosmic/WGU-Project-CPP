#include "student.h"
#include <iostream>

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int day1, int day2, int day3, DegreeProgram degree) {
    StudentID = studentID;
    FirstName = firstName;
    LastName = lastName;
    EmailAddress = emailAddress;
    Age = age;
    DaysToComplete[0] = day1;
    DaysToComplete[1] = day2;
    DaysToComplete[2] = day3;
    Degree = degree;
}

void Student::setStudentID(string ID) {
	StudentID = ID;
}
void Student::setFirstName(string FN) {
    FirstName = FN;
}
void Student::setLastName(string LN) {
    LastName = LN;
}
void Student::setEmailAddress(string EA) {
    EmailAddress = EA;
}
void Student::setAge(int A) {
    Age = A;
}
void Student::setDaysToComplete(int arr[], int max) {
    for (int i = 0; i < max; i++) {
        DaysToComplete[i] = arr[i];
    }
}
void Student::setDegreeProgram(DegreeProgram DP) {
    Degree = DP;
}
string Student::getStudentID() {
    return StudentID;
}
string Student::getFirstName() {
    return FirstName;
}
string Student::getLastName() {
    return LastName;
}
string Student::getEmailAddress() {
    return EmailAddress;
}
int Student::getAge() {
    return Age;
}
int* Student::getDaysToComplete() {
    return DaysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
    return Degree;
}
void Student::print(string specificData) {
    if (specificData == "StudentID") {
        std::cout << getStudentID();
    }
    else if (specificData == "FirstName") {
        std::cout << "\tFirst Name: " << getFirstName();
    }
    else if (specificData == "LastName") {
        std::cout << "\tLast Name: " << getLastName();
    }
    else if (specificData == "EmailAddress") {
        std::cout << "\tEmail: " << getEmailAddress();
    }
    else if (specificData == "Age") {
        std::cout << "\tAge: " << to_string(getAge());
    }
    // left off here
    else if (specificData == "DaysToComplete") {
        int* dtc = getDaysToComplete();
        std:cout << "\tdaysInCourse: { " << *(dtc) << ", " << *(dtc + 1) << ", " << *(dtc + 2) << " }";
    }
    else if (specificData == "DegreeProgram") {
        DegreeProgram degreeProgram = getDegreeProgram();
        std::cout << "\tDegree Program: ";
        switch (degreeProgram) {
        case DegreeProgram::SECURITY:
            std::cout << "Security" << endl;
            break;
        case DegreeProgram::NETWORK:
            std::cout << "Network" << endl;
            break;
        case DegreeProgram::SOFTWARE:
            std::cout << "Software" << endl;
            break;
        }
    }
    else {
        std::cout << "Not a valid request." << endl;
    }
    
}