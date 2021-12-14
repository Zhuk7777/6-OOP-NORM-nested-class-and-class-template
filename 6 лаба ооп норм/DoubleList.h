#pragma once
#include<string>
#include<iostream>

template <class X>
class DoubleList
{

	X data;
	DoubleList* next;
	DoubleList* prev;
	static DoubleList* head;
	static DoubleList* tail;

	void init(X elem);

public:

	DoubleList();
	DoubleList(X elem, DoubleList* _prev = nullptr, DoubleList* _next = nullptr);
	~DoubleList();

	bool isEmpty();
	bool isElemInList(X elem);

	DoubleList* createFromTail(X count);
	DoubleList* begin();

	void addAfterNode(X place, X value);
	void addTohead(X value);
	void addToTail(X value);

	void clearList();

	void deleteAfterNode(DoubleList* place);
	void deleteHead();
	void deleteTail();

	X getValueHead();
	X getValueTail();
	std::string toString();

	class iterator
	{
		DoubleList* pointer;

	public:

		iterator(const iterator& other) : pointer(other->pointer) {};
		iterator(DoubleList<X>* node) : pointer(node) {};

		iterator& operator=(const iterator& other)
		{
			if (pointer != other.pointer)
				pointer = other.pointer;
			return *this;
		}

		X& operator*()
		{
			return pointer->data;
		}

		bool operator==(const iterator& other)
		{
			return pointer == other.pointer;
		}

		bool operator!=(const iterator& other)
		{
			return pointer != other.pointer;
		}

		iterator& operator++()
		{
			return pointer = pointer->next;
		}

		iterator& operator++(int)
		{
			iterator* dop = this;
			pointer = pointer->next;
			return *dop;
		}

		iterator& operator--()
		{
			return pointer = pointer->prev;
		}

		iterator& operator--(int)
		{
			iterator* dop = this;
			pointer = pointer->prev;
			return *dop;
		}
	};
};

template<class X>
void DoubleList<X>::init(X elem)
{
	DoubleList* newElem = new DoubleList(elem);
	head = newElem;
	tail = newElem;
}

template<class X>
 DoubleList<X>::DoubleList()
{
	 head = nullptr;
	 tail = nullptr;
	 next = nullptr;
	 prev = nullptr;
}

template<class X>
DoubleList<X>::DoubleList(X elem, DoubleList* _prev, DoubleList* _next )
{
	data = elem;
	prev = _prev;
	next = _next;
}

template<class X>
DoubleList<X>::~DoubleList()
{
	prev = nullptr;
	next = nullptr;
}

template<class X>
bool DoubleList<X>::isEmpty()
{
	return head == nullptr;
}

template<class X>
bool DoubleList<X>::isElemInList(X elem)
{
	bool find = false;

	if (!isEmpty())
	{
		DoubleList* pointer = head;

		while ((pointer != nullptr) && (!find))
		{
			if (pointer->data == elem) find = true;
			else pointer = pointer->next;
		}
	}

	return find;
}

template<class X>
DoubleList<X>* DoubleList<X>::createFromTail(X count)
{
	clearList();
	X value;

	while (count)
	{
		std::cout << "¬ведите значение\n";
		std::cin >> value;

		if (isEmpty())
			init(value);
		else
			addToTail(value);
		count--;
	}
	return head;
}

template<class X>
DoubleList<X>* DoubleList<X>::begin()
{
	return head;
}

template<class X>
void DoubleList<X>::addAfterNode(X place, X value)
{
	if (isElemInList(place) && !isEmpty())
	{
		DoubleList* pos = head;

		while (pos->data != place && pos != nullptr)
			pos = pos->next;

		if (pos == tail) addToTail(value);
		else
		{
			DoubleList* newElem = new DoubleList(value, pos, pos->next);
			pos->next = newElem;
			pos->next->prev = newElem;

			newElem = nullptr;
		}
	}
}

template<class X>
void DoubleList<X>::addTohead(X value)
{
	if (isEmpty())
		init(value);
	else {
		DoubleList* newElem = new DoubleList(value,nullptr,head);
		head->prev = newElem;
		head = newElem;
		newElem = nullptr;
	}
}

template<class X>
void DoubleList<X>::addToTail(X value)
{
	if (isEmpty())
		init(value);
	else
	{
		DoubleList* newElem = new DoubleList(value,tail,nullptr);
		tail->next = newElem;
		tail = newElem;
		newElem = nullptr;
	}
}

template<class X>
void DoubleList<X>::clearList()
{
	if (!isEmpty())
	{
		while (head->next)
			deleteTail();
		deleteHead();
	}
}

template<class X>
void DoubleList<X>::deleteAfterNode(DoubleList* place)
{
	if (place->next != nullptr)
	{
		DoubleList* del = place->next;

		place->next = del->next;

		if (del->next != nullptr) del->next->prev = place;

		delete del;
		del = nullptr;
	}
}

template<class X>
void DoubleList<X>::deleteHead()
{
	if (!isEmpty())
	{
		DoubleList* dop = head;
		head = head->next;
		dop->next = nullptr;
		delete dop;
		dop = nullptr;
	}
}

template<class X>
void DoubleList<X>::deleteTail()
{
	if (!isEmpty())
	{
		DoubleList* dop = tail;

		if (tail->prev != nullptr)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}

		delete dop;
		dop = nullptr;
	}
}

template<class X>
X DoubleList<X>::getValueHead()
{
	if (!isEmpty())
		return head->data;
}

template<class X>
X DoubleList<X>::getValueTail()
{
	if (!isEmpty())
		return tail->data;
}

template<class X>
std::string DoubleList<X>::toString()
{
	if (!isEmpty())
	{
		std::string str;
		DoubleList* pointer = head;

		while (pointer)
		{
			str += std::to_string(pointer->data);
			str += " ";
			pointer = pointer->next;
		}
		pointer = nullptr;
	}
}

template <class X>
DoubleList<X>* DoubleList<X>::head = nullptr;
template <class X>
DoubleList<X>* DoubleList<X>::tail = nullptr;
