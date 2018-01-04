// DemoBasicCPPClass03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CPerson.h"
#include <vector>
#include <algorithm>

void DoTest()
{
	// CStudent + CPerson constructor invoked.
	// CPerson constructor invoked before CStudent constructor.
	CPerson* pPerson = new CStudent("George", 23, "NTU");

	if (pPerson != NULL)
	{
		// CStudent + CPerson destructor invoked.
		// CStudent destructor invoked before CPerson destructor.
		// This is a demonstration of the virtual destructor.
		delete pPerson;
		pPerson = NULL;
	}

	CPerson person1("David", 20);

	// CPerson copy constructor invoked.
	CPerson person2 = person1;

	CPerson person3("Bob", 18);

	// CPerson assignment operator invoked.
	person3 = person1;

	// CStudent + CPerson constructor invoked.
	// CPerson constructor invoked before CStudent constructor.
	CStudent student1("Jones", 19, "NTU");

	// CPerson copy constructor invoked.
	// The parameter passed into the copy constructor
	// is a CStudent object cast to a CPerson object.
	CPerson person4 = student1;

	// CPerson assignment operator invoked.
	// The parameter passed into the assignment operator
	// is a CStudent object cast to a CPerson object.
	person3 = student1;
}

void DoTest2()
{
	CPerson person1("George", 23);
	CPerson person2("Jack", 30);
	CPerson person3("Tom", 12);
	CPerson person4("Peter", 45);

	std::vector<CPerson> vecPerson;

	// push_back() invokes the copy constructor of the
        // object to be inserted, as well as other functions
        // (e.g. the destructor) of its existing objects as
        // part of an internal reorganization process.
	vecPerson.push_back(person1);
	vecPerson.push_back(person2);
	vecPerson.push_back(person3);
	vecPerson.push_back(person4);

	// sort() invokes a variety of functions including
	// the '<' operator, the copy constructor, the destructor
	// and the assignment operator.
	std::sort(vecPerson.begin(), vecPerson.end());

	// The following code is one means of using an iterator
	// to traverse a vector.
	//
	// Iterators will be explored further in future articles.
	std::vector<CPerson>::iterator theIterator;

	for (theIterator = vecPerson.begin(); theIterator != vecPerson.end(); theIterator++)
	{
		CPerson& person = *theIterator;
		person.SayNameAndAge();
	}
}

int main()
{
	DoTest();
	DoTest2();
    return 0;
}