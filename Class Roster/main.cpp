#include "roster.h"

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ricky,Ricardo,RickyBoi292@aol.com,27,10,20,31,SOFTWARE"
	};

	cout << "Language: C++\n";

	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Full Student Roster: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "List of invalid Email Addresses: " << std::endl;
	classRoster.printInvalidEmailAddress();
	cout << std::endl;

	cout << "List of average course days: " << std::endl;
	for (int i = 0; i < numStudents; i++) classRoster.printAverageDaysInCourse(studentData[i]);
	cout << std::endl;

	cout << "Displaying Software Students: " << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << "Removing StudentID A3: " << std::endl;
	classRoster.remove("A3");

	cout << "Removing StudentID A3: " << std::endl;
	classRoster.remove("A3");

	cout << "Calling Destructor" << std::endl;
	classRoster.~Roster();

	system("Pause...");
	return 0;
}