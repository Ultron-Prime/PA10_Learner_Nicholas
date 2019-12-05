/* -------------------------------------------------
FILE:		NodeStack.h
DESCRIPTION:	NodeStack header/C++ file for Project 10 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		Both class Node and class NodeStack are slightly adjusted from class Node and class NodeQueue in Proj9 

MODIFICATION HISTORY:
Author		Date		Version
------------	----------	-------------------------------------------------------------
Version 1	YYYY-MM-DD	x.x Description
Nick Learner	2019-11-25	1.0 Created this file, added non-templated class declarations
Nick Learner	2019-11-27	1.1 Added implementations, templating
*/

#ifndef NODESTACK_H_
#define NODESTACK_H_

#include <iostream>

template <class T> class Node;
template <class T> class NodeStack;
template <class T> std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack);

template <class T>
class Node
{
	friend class NodeStack<T>;
	
	public:
		Node(): m_next(NULL) { }
		Node(const T & data, Node<T> * next = NULL): m_next(next), m_data(data) { }
		Node(const Node<T> & other): m_next(other.m_next), m_data(other.m_data) { }
		
		T & data()
		{
			return m_data;
		}
		
		const T & data() const
		{
			return m_data;
		}
		
		Node<T> * next()
		{
			return m_next;
		}
		
		const Node<T> * next() const
		{
			return m_next;
		}
	private:
		Node<T> * m_next;
		T m_data;
};

template <class T>
class NodeStack
{
	friend std::ostream & operator<< <>(std::ostream & os, const NodeStack<T> & nodeStack);//(i)
	
	public:
		NodeStack();						//(1)
		NodeStack(size_t count, const T & value = T());		//(2)
		NodeStack(const NodeStack<T> & other);			//(3)
		~NodeStack();						//(4)
		
		NodeStack<T> & operator= (const NodeStack<T> & rhs);	//(5)
		
		T & top();						//(6a)
		const T & top() const;					//(6b)
		
		void push(const T & value);				//(7)
		void pop();						//(8)
		
		size_t size() const;					//(9)
		bool empty() const;					//(10)
		bool full() const;					//(11)
		void clear();						//(12)
		
		void serialize(std::ostream & os) const;		//(13)
	private:
		Node<T> * m_top;
		size_t m_size;
};


//(1)
template <class T>
NodeStack<T>::NodeStack(): m_top(NULL), m_size(0) { }

//(2)
template <class T>
NodeStack<T>::NodeStack(size_t size, const T & value): m_top(NULL), m_size(0)
{
	for (size_t i = 0; i < size; ++i)
		push(value);

}

//(3)
template <class T>
NodeStack<T>::NodeStack(const NodeStack<T> & other): m_top(NULL), m_size(0)
{
	for (Node<T> * curr = other.m_top; curr != NULL; curr = curr->m_next)
		push(curr->m_data);
}

//(4)
template <class T>
NodeStack<T>::~NodeStack()
{
	while(m_size)
		pop();
	
	std::cout << "NodeStack destructor called" << std::endl;
}

//(5)
template <class T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack<T> & rhs)
{
	if (this != &rhs)
	{
		while(m_size)
			pop();
		
		for (Node<T> * curr = rhs.m_top; curr != NULL; curr = curr->m_next)
			push(curr->m_data);
	}else;
	
	return *this;
}

//(6a)
template <class T>
T & NodeStack<T>::top()
{
	return m_top->m_data;
}

//(6b)
template <class T>
const T & NodeStack<T>::top() const
{
	return m_top->m_data;
}


//(7)
template <class T>
void NodeStack<T>::push(const T & value)
{
	if (m_size)
		m_top = new Node<T>(value, m_top);
	else
		m_top = new Node<T>(value);
	
	++m_size;
}

//(8)
template <class T>
void NodeStack<T>::pop()
{
	if (m_size != 0)
	{
		Node<T> * delnode = m_top;
		m_top = m_top->m_next;
		delete delnode;
		--m_size;
	}else;
}

//(9)
template <class T>
size_t NodeStack<T>::size() const
{
	return m_size;
}

//(10)
template <class T>
bool NodeStack<T>::empty() const
{
	return (m_size == 0);
}

//(11)
template <class T>
bool NodeStack<T>::full() const
{
	return false;
}

//(12)
template <class T>
void NodeStack<T>::clear()
{
	while(m_size)
		pop();
}

//(13)
template <class T>
void NodeStack<T>::serialize(std::ostream & os) const
{
	for (Node<T> * curr = m_top; curr != NULL; curr = curr->m_next)
		os << curr->m_data << std::endl;
}

//(i)
template <class T>
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack)
{
	nodeStack.serialize(os);
	return os;
}

#endif //ARRAYSTACK_H_

