#pragma once
#include "Node.h"
template <class T>
class DoublyLinkedList
{
private:
	Node<T>* first;
	Node<T>* last;
public:
	DoublyLinkedList()
	{
		first = nullptr;
		last = nullptr;
	}
	const Node<T>* getFirst()
	{
		return first;
	}
	const Node<T>* getLast()
	{
		return last;
	}
	void append(Node<T>* node)
	{
		last->setNext(node);
		node->setPrevious(last);
	}
	void insert(Node<T>* node, int location)
	{
		assert(location >= 0);
		if (location > 0)
		{
			Node<T>* preceeding = first;
			for (int x = 0; x < location; x++)
			{
				preceeding = preceeding->getNext();
			}
			Node<T>* following = preceeding->getNext();
			preceeding->setNext(node);
			following->setPrevious(node);
			node->setPrevious(preceeding);
			node->setNext(following);
		}
		else
		{
			first->setPrevious(node);
			node->setNext(first);
			first = first->getPrevious();
		}
	}
	void clear()
	{
		Node<T>* next = last;
		while (next != first)
		{
			next = next->getPrevious();
			delete next->getNext();
		}
	}
	~DoublyLinkedList()
	{
		clear();
	}
};