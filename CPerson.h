// CPerson.h

#pragma once

#include <string>
#include <iostream>

class CPerson
{
public:
	CPerson(const char* szName, int age);
    virtual ~CPerson();
	CPerson(const CPerson& rhs);
	CPerson& operator=(const CPerson& rhs);
	bool operator<(CPerson& rhs);

	void SayNameAndAge();

protected :
	char		szName[256];
	int         age;
};

class CStudent : public CPerson
{
public :
	CStudent(const char* szName, int age, const char* szSchool);
	virtual ~CStudent();

private :
	char	szSchool[256];
};

