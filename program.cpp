#include "sm.h"
#include "list.h"
#include "set.h"

customSP<int> foo(int x)
{
	customSP<int> a(x);
	return a;
}
int main()
{
	customSP<int> a = foo(5);
	cout << *a << "\t" << a.count() << endl;
	customSP<int> b = a;
	cout << *b << "\t" << b.count() << endl;

	cList<int> l;
	l.input(5);
	l.input(6);
	l.input(7);
	l.input(8);
	l.printList();
	l.erase(6);
	//l.printList();
	for (cList<int>::Iterator i = l.begin(); i != l.end(); i++)
	{
		cout << *i << endl;
	}
	for (cList<int>::reverseIterator i = l.rbegin(); i != l.rend(); i++)
	{
		cout << *i << endl;
	}

	cSet<int> s;
	s.input(5);
	s.input(6);
	s.input(5);
	s.input(4);
	s.input(2);
	s.input(0);
	s.input(1);
	s.erase(4);
}