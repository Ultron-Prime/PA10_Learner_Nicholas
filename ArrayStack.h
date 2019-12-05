/* -------------------------------------------------
FILE:		ArrayStack.h
DESCRIPTION:	ArrayStack header/C++ file for Project 10 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		Doesn't implement a copy constructor, destructor, or assignment operator

MODIFICATION HISTORY:
Author		Date		Version
------------	----------	------------------------------------------------------------------------
Version 1	YYYY-MM-DD	x.x Description
Nick Learner	2019-11-25	1.0 Created this file, added non-templated class ArrayStack declarations
Nick Learner	2019-11-27	1.1 Added implementations, templating
*/

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <iostream>

const size_t MAX_STACKSIZE = 1000;

template <class T> class ArrayStack;
template <class T> std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack);

template <class T>
class ArrayStack
{
	friend std::ostream & operator<< <>(std::ostream & os, const ArrayStack<T> & arrayStack);//(i) 
	
	public:
		ArrayStack();						//(1)
		ArrayStack(size_t count, const T & value = T());	//(2)
		//ArrayStack(const ArrayStack<T> & other);		//(3) (Unnecessary)
		//~ArrayStack();					//(4) (Unnecessary)
		
		//ArrayStack<T> & operator=(const ArrayStack<T> & rhs);	//(5) (Unnecessary)
		
		T & top();						//(6a)
		const T & top() const;					//(6b)
		
		void push(const T & value);				//(7)
		void pop();                  				//(8)
		
		size_t size() const;					//(9)
		bool empty() const;					//(10)
		bool full() const;					//(11)
		void clear();						//(12)
		
		void serialize(std::ostream & os) const;		//(13)
	private:
		T m_container[MAX_STACKSIZE];
		size_t m_top;
};

//(1)
template <class T>
ArrayStack<T>::ArrayStack(): m_top(0) { }

//(2)
template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T & value): m_top(0)
{
	for (size_t i = 0; i < count; ++i)
		push(value);
}

//(3)
/*template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack & other)			Unnecessary
{
	
}*/

//(4)
/*template <class T>
ArrayStack<T>::~ArrayStack()						Unnecessary
{
	
}*/

//(5)
/*template <class T>
ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs)	Unnecessary
{
	
}*/

//(6a)
template <class T>
T & ArrayStack<T>::top()
{
	return m_container[m_top-1];
}

//(6b)
template <class T>
const T & ArrayStack<T>::top() const
{
	return m_container[m_top-1];
}


//(7)
template <class T>
void ArrayStack<T>::push(const T & value)
{
	if (m_top != MAX_STACKSIZE)
	{
		m_container[m_top] = value;
		++m_top;
	}else;
}

//(8)
template <class T>
void ArrayStack<T>::pop()
{
	if (m_top != 0)
	{
		--m_top;
	}else
	{
		clear();
	}
}

//(9)
template <class T>
size_t ArrayStack<T>::size() const
{
	return m_top;
}

//(10)
template <class T>
bool ArrayStack<T>::empty() const
{
	return (m_top == 0);
}

//(11)
template <class T>
bool ArrayStack<T>::full() const
{
	return (m_top == MAX_STACKSIZE);
}

//(12)
template <class T>
void ArrayStack<T>::clear()
{
	m_top = 0;
}

//(13)
template <class T>
void ArrayStack<T>::serialize(std::ostream & os) const
{
	for (size_t i = 0; i < m_top; ++i)
		os << m_container[i] << std::endl;
}

//(i)
template <class T>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack)
{
	arrayStack.serialize(os);
	return os;
}

#endif //ARRAYSTACK_H_

