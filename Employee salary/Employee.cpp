#include "Employee.h"

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "Utils.h"

using namespace std;

Employee::Employee(string id, string name, int WorkDays, int Products, int salary)
{
	_id = id;
	_WorkDays = WorkDays;
	_Products = Products;
	Salary = salary;
	_name = name;

	vector <string> temp = Utils::String::split(name, " ");
	_fname = temp[0];
	_mname = temp[1];
	_lname = temp[2];
}

int Employee::getSalary(int WorkDays, int Products)
{
	int salary = Products * WorkDays * 1000;

	return salary;
}

string Employee::middlename()
{
	return _mname;
}

Employee Employee::parse(string data)
{
	const string Space = " ";
	string buffer;

	size_t foundPos = data.find_first_of(Space);
	string info = data.substr(foundPos + 1, data.length() - foundPos - 1);

	const string Separator = ", ";
	auto tokens = Utils::String::split(info, Separator);

	const string Divider = "=";

	auto pair1 = Utils::String::split(tokens[0], Divider);
	string id = pair1[1];

	auto pair2 = Utils::String::split(tokens[1], Divider);
	string name = pair2[1];

	auto pair3 = Utils::String::split(tokens[2], Divider);
	buffer = pair3[1];
	int workdays = stoi(buffer);

	auto pair4 = Utils::String::split(tokens[3], Divider);
	buffer = pair4[1];
	int products = stoi(buffer);

	int salary = getSalary(workdays, products);

	Employee p(id, name, workdays, products, salary);
	return p;
}

vector <Employee> Employee::getAll()
{
	vector <Employee> result;

	string filename = "salary112022.txt";

	ifstream input;
	input.open(filename);
	string tmp;

	getline(input, tmp);

	while (!input.eof())
	{
		string buffer;
		getline(input, buffer);

		Employee p = parse(buffer);
		result.push_back(p);
	}

	return result;
}

string Employee::toString()
{
	stringstream builder;

	builder << "Employee ID = " << _id << ", Name = " << _fname << " " << _mname << " " << _lname << ", WorkDays = " << _WorkDays << ", Products = " << _Products << ", Salary = " << Salary << " VND";

	string result = builder.str();
	return result;
}

void Print()
{
	Employee q;
	auto employee = q.getAll();

	for (int i = 0; i < employee.size() - 1; i++)
		for (int j = i + 1; j < employee.size(); j++)
		{
			vector<string>temp = { employee[i].middlename(), employee[j].middlename() };
			if (temp[0] > temp[1])
				swap(employee[i], employee[j]);
		}

	for (int i = 0; i < employee.size() - 1; i++)
		for (int j = i + 1; j < employee.size(); j++)
			if (employee[i].Salary < employee[j].Salary)
				swap(employee[i], employee[j]);


	for (auto p : employee)
	{
		cout << p.toString() << endl;
	}
}