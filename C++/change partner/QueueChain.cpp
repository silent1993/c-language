
#include <iostream>
#include "QueueChain.h"

using std::cout;
using std::endl;


template <class Type>
LinkedQueue<Type>::~LinkedQueue()
{
	Node<Type> * next;
	while (front)
	{
		next = front->link;
		delete front;
		front = next;

	}
}


template <class Type>
Type LinkedQueue<Type>::First()const
{
	if (IsEmpty())
		cout << "erro" << endl;
	else
		return front->data;
}


template <class Type>
Type LinkedQueue<Type>::Last()const
{
	if (IsEmpty())
		cout << "erro" << endl;
	else
	{
		return rear->data;
	}
}


template<class Type>
void LinkedQueue<Type>::Add(const Type&x)
{
	Node <Type>*p = new Node<Type>;
	p->data = x;
	p->link = 0;
	if (front)
		rear->link = p;
	else
		front = p;


}
template<class Type>
void LinkedQueue<Type>::Delete( Type&x)
{
	if (IsEmpty())
		cout << "erro" << endl;
	else
	{
		x = front->data;
		Node<Type>*p = front;
		front = front->link;
		delete p;

	}
}
