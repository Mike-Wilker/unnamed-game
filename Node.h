#pragma once
template <class T>
class Node
{
private:
	T* object;
	Node<T>* previous;
	Node<T>* next;
public:
	Node<T>(T* object)
	{
		this->object = object;
		previous = nullptr;
		next = nullptr;
	}
	T* getObject()
	{
		return object;
	}
	Node<T>* getPrevious()
	{
		return previous;
	}
	Node<T>* getNext()
	{
		return next;
	}
	void setPrevious(Node<T>* previous)
	{
		this->previous = previous;
	}
	void setNext(Node<T>* next)
	{
		this->next = next;
	}
	~Node<T>()
	{
		delete object;
	}
};