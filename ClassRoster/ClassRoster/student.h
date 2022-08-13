#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
    string StudentID;
    string FirstName;
    string LastName;
    string EmailAddress;
    int Age;
    int DaysToComplete[3];
    DegreeProgram Degree;

public:
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int day1, int day2, int day3, DegreeProgram degree);

    void setStudentID(string ID);

    void setFirstName(string FN);

    void setLastName(string LN);

    void setEmailAddress(string EA);

    void setAge(int A);

    void setDaysToComplete(int arr[], int i);

    void setDegreeProgram(DegreeProgram DP);

    string getStudentID();

    string getFirstName();

    string getLastName();

    string getEmailAddress();

    int getAge();

    int* getDaysToComplete();

    DegreeProgram getDegreeProgram();

    void print(string specificData);

};
