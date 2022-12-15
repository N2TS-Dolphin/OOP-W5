#pragma once
#include <iostream>
#include <vector>

using namespace std;

void Print();

class Employee
{
private:
	string _id;
	string _name;
	string _fname;
	string _mname;
	string _lname;
	int _WorkDays;
	int _Products;

public:
	int Salary;
	string middlename();

public:
	Employee() { }
	Employee(string, string, int, int, int);
	Employee parse(string data);

public:
	int getSalary(int, int);
	vector <Employee> getAll();
	string toString();
};