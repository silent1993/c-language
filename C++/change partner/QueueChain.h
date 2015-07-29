#ifndef QUEUECHAIN_H_
#define QUEUECHAIN_H_
template<class Type>
class Node
{
	Type name;
	Node<Type> *link;
};




template <class Type>
class LinkedQueue
{
private:
	Node<Type> *front;
	Node<Type> *rear;
public:
	LinkedQueue(){ front = rear = 0; }
	~LinkedQueue();
	bool IsEmpty()const{ return front==rear; }
	Type First()const;
	Type Last()const;
	void  Add(const Type&x);
	void  Delete( Type &x);
};


#endif // !QUEUECHAIN_H_

