//////////////////
//Anna Tran
//CS 172-Sec1 
//11.13
//////////////////
#include<iostream>
#include"Course.h"
using namespace std;

Course::Course(const string& courseName, int capacity)
{
	int numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];

}

Course::~Course()
{
	delete[]students;
}
string Course::getCourseName() const
{
	return courseName;
}
//Add new function to increase array size
void Course::expand(int nsize)
{
	string*nstudent;
	//make new array
	nstudent = new string[nsize];
	//copy old array into new array
	for (int i = 0; i < numberOfStudents; i++)
		students[i] = nstudent[i];
	//delete old array
	delete []students;
	//assign to new array
	students = nstudent;
	capacity = nsize;

}
void Course::addStudent(const string& name)
{
	//check if capacity is full
	if (numberOfStudents == capacity)
	{
		expand(capacity * 2);
	}
	students[numberOfStudents] = name;
	numberOfStudents++;

}
void Course::dropStudent(const string& name)
{
	students[numberOfStudents] = name;
	numberOfStudents--;
}
string* Course::getstudents() const
{
	return students;
}
int Course::getNumberOfStudents()const
{
	return numberOfStudents;
}
void Course::clear()
{
	for (int i = 0; i < numberOfStudents; i++)
//Use clear function to clear array of students
		students[numberOfStudents]=0;
// delete[] students?????
}
//copy constructor for deep copy
Course::Course(const Course& course)
{
	courseName = course.courseName;
	numberOfStudents = course.numberOfStudents;
	capacity = course.capacity;
	students = new string[capacity];
}