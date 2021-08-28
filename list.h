#ifndef _LIST_H
#define _LIST_H
#include <iostream>
using namespace std;

template <class T>
class cNode
{
public:
	T data;
	cNode* next;
	cNode* prev;
};

template <class T>
class cList
{
	int counter;
	cNode<T>* head;
	cNode<T>* back;
public:
	cList()
	{
		counter = 0;
		head = NULL;
		back = NULL;
	}
	void input(const T& a)
	{
		if (counter == 0)
		{
			counter = 1;
			head = new cNode<T>;
			head->data = a;
			head->next = NULL;
			head->prev = NULL;
			back = head;
			return;
		}
		counter++;
		cNode<T>* tmp = new cNode<T>;
		tmp->data = a;
		tmp->next = NULL;
		tmp->prev = back;
		back->next = tmp;
		back = tmp;
	}
	void erase(const T& a)
	{
		if (counter == 0)
			return;
		cNode<T>* tmp = head;
		cNode<T>* tmp2 = head;
		while (tmp->data == a)
		{
			if (head->next != NULL)
				head->next->prev = NULL;
			head = head->next;
			delete tmp;
			tmp = head;
			counter--;		
			if (counter == 0)
				return;
		}
		while (tmp != NULL)
		{
			if (tmp->data == a)
			{
				tmp2->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = tmp2;
				delete tmp;
				tmp = tmp2;
				counter--;
			}
			tmp2 = tmp;
			tmp = tmp->next;
		}
		
	}
	void printList()
	{
		if (counter == 0)
			cout << "Empty list.\n";
		cNode<T>* tmp = head;
		for (int i = 0; i < counter; i++)
		{
			cout << tmp->data << "  ";
			tmp = tmp->next;
		}
		cout << endl;
		
	}
	class Iterator
	{
	private:
		cNode<T>* head;
	public:
		Iterator(cNode<T>* head)
		{ 
			this->head = head; 
		}
		Iterator operator++(int) { Iterator itr = *this; head = head->next; return itr; }
		T& operator*() { return head->data; }
		bool operator==(const Iterator& itr) { return head == itr.head; }
		bool operator!=(const Iterator& itr) { return head != itr.head; }
		
	};
	class reverseIterator
	{
	private:
		cNode<T>* head;
	public:
		reverseIterator(cNode<T>* head)
		{
			this->head = head;
		}
		reverseIterator operator++(int) { reverseIterator itr = *this; head = head->prev; return itr; }
		T& operator*() { return head->data; }
		bool operator==(const reverseIterator& itr) { return head == itr.head; }
		bool operator!=(const reverseIterator& itr) { return head != itr.head; }

	};
	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return Iterator(NULL); }
	reverseIterator rbegin() const { return reverseIterator(back); }
	reverseIterator rend() const { return reverseIterator(NULL); }
};


#endif