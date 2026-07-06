#include <iostream>

#include <iomanip>

using namespace std;

double getGradePoint(string grade)

{

if (grade=="A+"||grade=="A")

return 4.0;

else if (grade=="A-")

return 3.7;

else if (grade=="B+")

return 3.3;

else if (grade=="B")

return 3.0;

else if (grade=="B-")

return 2.7;

else if (grade=="C+")

return 2.3;

else if (grade=="C")

return 2.0;

else if (grade=="D")

return 1.0;

else

return 0.0;

}

int main()

{

int semesters;

double totalPoints=0;

int totalCredits=0;

cout<<"Enter number of semesters: ";

cin>>semesters;

for(int i=1;i<=semesters;i++)

{

int courses;

double semesterPoints=0;

int semesterCredits=0;

cout<<"\nSemester " <<i<<endl;

cout<<"Enter number of courses: ";

cin>>courses;

for (int j=1;j<=courses;j++)

{

string grade;

int credits;

cout<<"\nCourse "<<j<<endl;

cout<<"Enter grade (A, B+, A-, etc): ";

cin>>grade;

cout<<"Enter credit hours: ";

cin>>credits;

double gp=getGradePoint(grade);

semesterPoints=semesterPoints+gp*credits;

semesterCredits=semesterCredits+credits;

}

double gpa=semesterPoints/semesterCredits;

cout<<fixed<<setprecision(2);

cout<<"Semester GPA="<<gpa<<endl;

totalPoints=totalPoints+semesterPoints;

totalCredits=totalCredits+semesterCredits;

}

double cgpa=totalPoints/totalCredits;

cout<<"\n=========================\n";

cout<<"Overall CGPA= "<<cgpa<<endl;

char choice;

cout<<"\nDo you want to predict future GPA? (y/n): ";

cin>>choice;

if (choice=='y'||choice=='Y')

{

double targetCGPA;

int remainingCredits;

cout<<"Enter target CGPA: ";

cin>>targetCGPA;

cout<<"Enter remaining credit hours: ";

cin>>remainingCredits;

double requiredPoints=

targetCGPA*(totalCredits+remainingCredits);

double neededPoints=

requiredPoints-totalPoints;

double requiredGPA=

neededPoints/remainingCredits;

if (requiredGPA>4.0)

{

cout<<"Target CGPA is not possible.\n";

}

else if (requiredGPA<0)

{

cout<<"You have already achieved your target.\n";

}

else

{

cout<<"You need a GPA of "

<<fixed<<setprecision(2)

<<requiredGPA

<<"in upcoming semesters.\n";

}

}

return 0;

}
