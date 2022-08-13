
#include <iostream>
#include "roster.h"
#include <string>

int main() {
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Clint,Mireles,cmirel7@wgu.edu,29,20,30,40,SOFTWARE"
    };

    Roster classRoster = Roster();
    int dataCount = 0;
    for (int i = 0; i < 5; i++) {
        string strData = studentData[i];
        
        size_t next;
        size_t finder = strData.find(',');
        string studentID = strData.substr(0, finder);

        next = strData.find(',', finder + 1);
        string firstName = strData.substr(finder + 1, next - 1 - finder);
        finder = next;

        next = strData.find(',', finder + 1);
        string lastName = strData.substr(finder + 1, next - 1 - finder);
        finder = next;

        next = strData.find(',', finder + 1);
        string emailAddress = strData.substr(finder + 1, next - 1 - finder);
        finder = next;

        next = strData.find(',', finder + 1);
        int age = stoi(strData.substr(finder + 1, next - 1 - finder));
        finder = next;

        next = strData.find(',', finder + 1);
        int daysInCourse1 = stoi(strData.substr(finder + 1, next - 1 - finder));
        finder = next;

        next = strData.find(',', finder + 1);
        int daysInCourse2 = stoi(strData.substr(finder + 1, next - 1 - finder));
        finder = next;

        next = strData.find(',', finder + 1);
        int daysInCourse3 = stoi(strData.substr(finder + 1, next - 1 - finder));
        finder = next;

        string degree = strData.substr(finder + 1, strData.size() - 1 - finder);
        DegreeProgram degreeprogram;
        if (degree.compare("SECURITY") == 0) {
            degreeprogram = DegreeProgram::SECURITY;
        }
        else if (degree.compare("NETWORK") == 0) {
            degreeprogram = DegreeProgram::NETWORK;
        }
        else {
            degreeprogram = DegreeProgram::SOFTWARE;
        }

        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
    }
 
    std::cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867, C++, ID# 001310038, Clint Mireles" << endl;
    std::cout << "All Students: " << endl;
    classRoster.printAll();
    
    std::cout << endl << "Invalid Emails: " << endl;
    classRoster.printInvalidEmails();

    std::cout << endl << "Average Days in Course: " << endl;
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudentID(i));
    }

    std::cout << endl << "Software Students: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    std::cout << endl << "All Students, 2nd time: " << endl;
    classRoster.printAll();

    std::cout << endl << "Attempt to Remove A3" << endl;
    classRoster.remove("A3");

    return 0;
}
