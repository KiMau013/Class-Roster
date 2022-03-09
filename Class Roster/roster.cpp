#include "roster.h"

void Roster::parse(string studentData)
{
	DegreeProgram dp = SECURITY;
	if (studentData.back() == 'K') dp = NETWORK;
	else if (studentData.back() == 'E') dp = SOFTWARE;

	int rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sFN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sLN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sEm = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int sAge = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d1 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d2 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d3 = stod(studentData.substr(lhs, rhs - lhs));

	add(sID, sFN, sLN, sEm, sAge, d1, d2, d3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp)
{
	int dayArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dayArray, dp);
}

void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " was removed from class roster." << std::endl << std::endl;
		cout << "Full Student Roster:" << std::endl;
		this->printAll();
		cout << std::endl;
	}
	else cout << studentID << " was not found." << std::endl << std::endl;
}

void Roster::printAll()
{
	Student::printTop();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << "First Name: " << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << "Last Name: " << classRosterArray[i]->getLastName(); cout << '\t';
		cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
		cout << "daysInCourse: {" << classRosterArray[i]->getDays()[0]; cout << ',';
		cout << classRosterArray[i]->getDays()[1]; cout << ',';
		cout << classRosterArray[i]->getDays()[2]; cout << "}\t";
		cout << "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	int averageDays = 0;
	int studentNum = (((int)studentID.at(1)) - 48) - 1;
	{
		averageDays = ((classRosterArray[studentNum]->getDays()[0]
			+ classRosterArray[studentNum]->getDays()[1]
			+ classRosterArray[studentNum]->getDays()[2]) / 3);
		cout << "Student ID: " << classRosterArray[studentNum]->getStudentID() << " averages " << averageDays << " days in a course." << std::endl;
	}
}

void Roster::printInvalidEmailAddress()
{
	bool valid = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string em = (classRosterArray[i]->getEmailAddress());
		if (em.find('@') == string::npos)
		{
			valid = true;
			cout << em << ": " << "Email does not have an @ symbol." << std::endl;
		}
		else if (em.find('.') == string::npos)
		{
			valid = true;
			cout << em << ": " << "Email does not have a period." << std::endl;
		}
		else if (em.find(' ') != string::npos)
		{
			valid = true;
			cout << em << ": " << "Email does not allow spaces." << std::endl;
		}
	}
	if (!valid) cout << "No Invalid E-mails." << std::endl;
}


void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printTop();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) {
			cout << classRosterArray[i]->getStudentID(); cout << '\t';
			cout << "First Name: " << classRosterArray[i]->getFirstName(); cout << '\t';
			cout << "Last Name: " << classRosterArray[i]->getLastName(); cout << '\t';
			cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
			cout << "daysInCourse: {" << classRosterArray[i]->getDays()[0]; cout << ',';
			cout << classRosterArray[i]->getDays()[1]; cout << ',';
			cout << classRosterArray[i]->getDays()[2]; cout << "}\t";
			cout << "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
		}
	}
	cout << std::endl;
}



Roster::~Roster()
{
	cout << "Destructor Initialized" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying Student Information: " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}