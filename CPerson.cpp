#include "stdafx.h"
#include "CPerson.h"

CPerson::CPerson(const char* szName, int age)
{
	strcpy(this->szName, szName);
	this->age = age;

	std::cout << "Constructor of CPerson " << szName << std::endl;
}

CPerson::~CPerson()
{
	std::cout << "Destructor of CPerson " << szName << std::endl;
}

CPerson::CPerson(const CPerson& rhs)
{
	strcpy(szName, rhs.szName);
	age = rhs.age;
	// Can also use the =operator() to do this, e.g. :
	//this->operator=(rhs);

	std::cout << "Copy constructor of CPerson " << szName << std::endl;
}

// Assignment operator.
CPerson& CPerson::operator=(const CPerson& rhs)
{
	strcpy(szName, rhs.szName);
	age = rhs.age;

	std::cout << "Assignment operator of CPerson " << szName << std::endl;

	return *this;  // Assignment operator returns left side.  
}

void CPerson::SayNameAndAge()
{
	std::cout << szName << " : " << age << std::endl;
}

bool CPerson::operator<(CPerson& rhs)
{
	return age < rhs.age;
}

CStudent::CStudent(const char* szName, int age, const char* szSchool) :
	CPerson(szName, age)
{
	strcpy(this->szSchool, szSchool);

	std::cout << "Constructor of CStudent " << szName << std::endl;
}

CStudent::~CStudent()
{
	std::cout << "Destructor of CStudent " << szName << std::endl;
}





