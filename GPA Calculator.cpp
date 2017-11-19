#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;
typedef map<string, string> mss;
typedef map<char, int> MC;
typedef set<int> S;
typedef long long ll;

#define mp make_pair
#define pb push_back
#define all(c)	c.begin(),c.end()
#define For(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int totalNumberOfStudents , numberOfSubjects , subjectMark;
string subjectGrade;


struct student{
	string name;
	double gpa;
	string maxGrade;
	string minGrade;
};
student strStudent;
vector<student> students;

double calculateGPA(int grade){
	if(grade < 50)	return 0.0;
	else if (grade >=50 && grade <60)	return 2.0;
	else if (grade >=60 && grade <65)	return 2.2;
	else if (grade >=65 && grade <70)	return 2.4;
	else if (grade >=70 && grade <75)	return 2.7;
	else if (grade >=75 && grade <80)	return 3.0;
	else if (grade >=80 && grade <85)	return 3.3;
	else if (grade >=85 && grade <90)	return 3.7;
	else return 4.0;
}

string calculateGpaGrade(int grade){
	if(grade < 50)	return "F";
	else if (grade >=50 && grade <60)	return "D";
	else if (grade >=60 && grade <65)	return "D+";
	else if (grade >=65 && grade <70)	return "C";
	else if (grade >=70 && grade <75)	return "C+";
	else if (grade >=75 && grade <80)	return "B";
	else if (grade >=80 && grade <85)	return "B+";
	else if (grade >=85 && grade <90)	return "A";
	else return "A+";
}

string generalGrade(double gpa){
	if(gpa < 2.0)	return "poor";
	else if(gpa >=2.0 && gpa <2.4)	return "Acceptable";
	else if(gpa >=2.4 && gpa <2.7)	return "good";
	else if(gpa>=2.7 && gpa <3.3)	return "Very Good";
	else return "Excellent";
}


int main() {
	int maxMark =0 , minMark = 101 ;
	double sumGpa = 0.0 , gpaAverage=0.0 , studentGpaAverage=0.0;
	string maxGrade, minGrade;
	string studentName, studentGeneralGrade;
	cout<<"Enter the Total number of Students : ";
	cin>>totalNumberOfStudents;
	for(int k =1;k<=totalNumberOfStudents;k++){
		sumGpa = 0.0 , gpaAverage=0.0 , studentGpaAverage=0.0;
		maxMark =0 , minMark = 101 ;


		cout<<"\nEnter student #"<<k<<" name : ";
		cin>>studentName;
		cout<<"\nEnter number of subjects : ";
		cin>>numberOfSubjects;
		for(int i=1;i<=numberOfSubjects;i++){
			cout<<"\nEnter marks for subject #"<<i<<" : ";
			cin>>subjectMark;
			/**
			 * this line if you want to enter the Grade like D+ , C+
			 * but it doesn't make any thing so its better to remove it
			 * */
			//cout<<"\nGrade for subject #"<<i<<" : ";
			//cin>>subjectGrade;
			sumGpa += calculateGPA(subjectMark);
			if(maxMark <= subjectMark){
				maxMark = subjectMark;
			}
			if(minMark >= subjectMark){
				minMark = subjectMark;
			}
		}
		gpaAverage = (sumGpa / (double)numberOfSubjects );

		maxGrade = calculateGpaGrade(maxMark);
		minGrade = calculateGpaGrade(minMark);
		studentGeneralGrade = generalGrade(gpaAverage);

		cout<<"\nGPA for "<<studentName<<" is : "<<gpaAverage;
		cout<<"\nMax grade is : "<<maxGrade;
		cout<<"\nMin grade is : "<<minGrade;
		cout<<"\nGeneral grade for "<<studentName<<" is "<<studentGeneralGrade;
		strStudent.name = studentName;
		strStudent.maxGrade = maxGrade;
		strStudent.minGrade = minGrade;
		strStudent.gpa = gpaAverage;
		students.push_back(strStudent);
	}
	cout<<"\n\t\t-------------------------------------------------";

	double highestGpa=0.0,lowestGpa=5.0;
	string topStudent, downStudent;
	for(int i=0;i<students.size();i++){
		studentGpaAverage += students[i].gpa ;
		if(highestGpa <= students[i].gpa){
			highestGpa = students[i].gpa;
			topStudent = students[i].name;
		}
		if(lowestGpa >= students[i].gpa){
			lowestGpa = students[i].gpa;
			downStudent = students[i].name;
		}
	}
	studentGpaAverage = (studentGpaAverage / (double)totalNumberOfStudents);
	cout<<"\nAverage GPA for students is : "<<studentGpaAverage;
	cout<<"\nHighest GPA for student "<<topStudent<<" is "<<highestGpa;
	cout<<"\nLowest GPA for student "<<downStudent<<" is "<<lowestGpa;
}
