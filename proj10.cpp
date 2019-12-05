/* -------------------------------------------------
FILE:		proj10.cpp
DESCRIPTION:	proj10 C++ file for Project 9 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		

MODIFICATION HISTORY:
Author		Date		Version
------------	----------	---------------------
Version 1	YYYY-MM-DD	x.x Description
Nick Learner	2019-11-25	1.0 Created this file
*/

#include "ArrayStack.h"
#include "NodeStack.h"
#include "DataType.h"

using namespace std;

int main()
{
	DataType data[10];
	
	cout << endl << "An array of DataType objects,\n" <<
		"used later in the program for the ArrayStack and NodeStack objects" << endl;
	
	for (size_t i = 0; i < 10; ++i)
	{
		data[i].setIntVal((int)i);
		data[i].setDoubleVal(-1.1 * (double)i);
		cout << data[i] << endl;
	}
	
	ArrayStack<DataType> a1;
	NodeStack<DataType> n1;
	ArrayStack<DataType> a2 = a1;
	NodeStack<DataType> n2(n1);
	ArrayStack<DataType> a3(4, data[4]);
	NodeStack<DataType> n3(6, data[2]);
	ArrayStack<double> ad(3, 13.13);
	NodeStack<char> nc(1, 'r');
	
	
	cout << "\n\n" << "Initializaton/output tests" << "\n\n";
	
	cout << "a1" << endl << a1 << endl;
	cout << "n1" << endl << n1 << endl;
	cout << "a2" << endl << a2 << endl;
	cout << "n2" << endl << n2 << endl;
	cout << "a3" << endl << a3 << endl;
	cout << "n3" << endl << n3 << endl;
	cout << "ad (ArrayStack object templated for doubles)" << endl << ad << endl;
	cout << "nc (NodeStack object templated for chars)" << endl << ad << endl;
	
	
	cout << endl << "ArrayStack tests" << "\n\n";
	
	cout << "a1.push(value)" << endl;
	a1.push(data[1]);
	cout << "new a1" << endl << a1 << endl;
	
	cout << "a2" << endl << a2 << endl;
	
	cout << "a2.push(value)" << endl;
	a2.push(data[2]);
	cout << "new a2" << endl << a2;
	cout << "a2.size() = " << a2.size() << "\n\n";
	
	cout << "a3.push(value)" << endl;
	a3.push(data[3]);
	cout << "new a3" << endl << a3;
	cout << "a3.size() = " << a3.size() << "\n\n";
	
	cout << "ad.push(value)" << endl;
	ad.push(4.4);
	cout << "new ad" << endl << ad;
	cout << "ad.size() = " << ad.size() << "\n\n";
	
	cout << "a1.pop()" << endl;
	a1.pop();
	cout << "new a1" << endl << a1 << endl;
	
	cout << "a2.pop()" << endl;
	a2.pop();
	cout << "new a2" << endl << a2 << endl;
	
	cout << "a3.pop()" << endl;
	a3.pop();
	cout << "new a3" << endl << a3 << endl;
	
	cout << "ad.pop()" << endl;
	ad.pop();
	cout << "new ad" << endl << ad << endl;
	
	cout << "Without checking whether the stacks are empty or not:" << endl;
	cout << "a1.top() = " << a1.top() << endl;
	cout << "a3.top() = " << a3.top() << endl;
	cout << "ad.top() = " << ad.top() << endl;
	
	cout << "a2.size() = " << a2.size() << endl;
	cout << "a3.size() = " << a3.size() << endl;
	cout << "ad.size() = " << ad.size() << endl;
	
	cout << endl << "Assigment operator test: a2 = a3" << endl;
	a2 = a3;
	cout << "new a2" << endl << a2 << endl;
	
	cout << "empty() tests" << endl;
	cout << "a1.empty() = " << boolalpha << a1.empty() << endl;
	cout << "a2.empty() = " << boolalpha << a2.empty() << endl;
	cout << "a3.empty() = " << boolalpha << a3.empty() << endl;
	cout << "ad.empty() = " << boolalpha << ad.empty() << "\n\n";
	
	cout << "full() tests" << endl;
	cout << "a1.full() = " << boolalpha << a1.full() << endl;
	cout << "a2.full() = " << boolalpha << a2.full() << endl;
	cout << "a3.full() = " << boolalpha << a3.full() << endl;
	cout << "ad.full() = " << boolalpha << ad.full() << "\n\n";
	
	cout << "a3.clear()" << endl;
	a3.clear();
	cout << "new a3" << endl << a3 << endl;
	
	
	cout << endl << "NodeStack tests" << "\n\n";
	
	cout << "n1.push(value)" << endl;
	n1.push(data[9]);
	cout << "new n1" << endl << n1 << endl;
	
	cout << "n2" << endl << n2 << endl;
	
	cout << "n2.push(value)" << endl;
	n2.push(data[8]);
	cout << "new n2" << endl << n2;
	cout << "n2.size() = " << n2.size() << "\n\n";
	
	cout << "n3.push(value)" << endl;
	n3.push(data[7]);
	cout << "new n3" << endl << n3;
	cout << "n3.size() = " << n3.size() << "\n\n";
	
	cout << "nc.push(value)" << endl;
	nc.push('e');
	nc.push('n');
	nc.push('r');
	nc.push('a');
	nc.push('e');
	nc.push('L');
	nc.push(' ');
	nc.push('k');
	nc.push('c');
	nc.push('i');
	nc.push('N');
	nc.push('9');
	cout << "new nc" << endl << nc;
	cout << "nc.size() = " << nc.size() << "\n\n";
	
	cout << "n1.pop(value)" << endl;
	n1.pop();
	cout << "new n1" << endl << n1 << endl;
	
	cout << "n2.pop(value)" << endl;
	n2.pop();
	cout << "new n2" << endl << n2 << endl;
	
	cout << "n3.pop(value)" << endl;
	n3.pop();
	cout << "new n3" << endl << n3 << endl;
	
	cout << "nc.pop(value)" << endl;
	nc.pop();
	cout << "new nc" << endl << nc << endl;
	
	cout << "Without checking whether the queues are empty or not:" << endl;
	//cout << "n1.top() = " << n1.top() << endl;
	cout << "n3.top() = " << n3.top() << endl;
	cout << "nc.top() = " << nc.top() << endl;
	
	cout << "n2.size() = " << n2.size() << endl;
	cout << "n3.size() = " << n3.size() << endl;
	cout << "nc.size() = " << nc.size() << endl;
	
	cout << endl << "Assigment operator test: n2 = n3" << endl;
	n2 = n3;
	cout << "new n2" << endl << n2 << endl;
	
	cout << "empty() tests" << endl;
	cout << "n1.empty() = " << boolalpha << n1.empty() << endl;
	cout << "n2.empty() = " << boolalpha << n2.empty() << endl;
	cout << "n3.empty() = " << boolalpha << n3.empty() << endl;
	cout << "nc.empty() = " << boolalpha << nc.empty() << "\n\n";
	
	cout << "full() tests" << endl;
	cout << "n1.full() = " << boolalpha << n1.full() << endl;
	cout << "n2.full() = " << boolalpha << n2.full() << endl;
	cout << "n3.full() = " << boolalpha << n3.full() << endl;
	cout << "nc.full() = " << boolalpha << nc.full() << "\n\n";
	
	cout << "n3.clear()" << endl;
	n3.clear();
	cout << "new n3" << endl << n3 << endl;
	
	cout << "Destructors:" << endl;

	
	return 0;
}

