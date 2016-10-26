#pragma once
#include<string>
using namespace std;

class Course
{
public:
	Course(const string& courseName, int capacity);
	~Course();
	string getCourseName() const;
	void expand(int size);
	void addStudent(const string& name);
	void dropStudent(const string& name);
	string* getstudents() const;
	int getNumberOfStudents() const;
	void clear();
	Course(const Course& course);
private:
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity;
};
