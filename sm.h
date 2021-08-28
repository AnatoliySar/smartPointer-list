#ifndef _SM_H
#define _SM_H
#include <iostream>
using namespace std;

template <class T>
class customSP
{
	T* data;
	int* counter;
public:
	customSP(); // ����������� ��� ����������: ������� ������ ��������� � ��������� 0
	customSP(T smthng); // ����������� � ����������: ������� ��������� � ��������� 1, 
						//������ ����� smthng (��� ������ smthng �������� � ������������ ������)
	customSP(const customSP& ptr); //����������� �����������, ����������� �������
	void release(); // ����������� ����� ���������	
	int count();
	customSP operator=(const customSP& a); // �������� ������������, ����������� �������
	T operator*(); // ������������� �������� �������������
	~customSP(); // ����������
};
template<class T> customSP<T>::customSP()
{
	data = NULL;
	counter = new int(0);
}
template<class T> customSP<T>::customSP(T smthng)
{
	data = new T(smthng);
	counter = new int(1);
}
template<class T> customSP<T>::customSP(const customSP& ptr)
{
	release();
	if (ptr.data == NULL)
		return;
	data = ptr.data;
	counter = ptr.counter;
	*counter += 1;
}
template<class T> void customSP<T>::release()
{
	delete data;
	data = NULL;
	delete counter;
	counter = NULL;
}
template<class T> customSP<T> customSP<T>:: operator=(const customSP& a)
{
	this->data = new int(7);
	this->counter = a.counter;
	*this->counter += 1;
	return *this;
}
template<class T> T customSP<T>::operator*()
{
	return *data;
}
template<class T> int customSP<T>::count()
{
	return *counter;
}
template<class T> customSP<T>::~customSP()
{
	if (*counter <= 1)
	{
		release();
		cout << "\npointer deleted\n";
	}
	else
	{
		(*counter)--;
		cout << "\ncopy count decreased\n";
	}

}
#endif
