#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysArraySize];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
	~Student();

	/*Accessors*/
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	/*Mutators*/
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printTop();

	void print();
};
