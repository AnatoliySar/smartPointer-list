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
	customSP(); // конструктор без параметров: создает пустой указатель с счетчиком 0
	customSP(T smthng); // конструктор с параметром: создает указатель с счетчиком 1, 
						//хранит адрес smthng (сам объект smthng хранится в динамической памяти)
	customSP(const customSP& ptr); //конструктор копирования, увеличивает счетчик
	void release(); // освобождает умный указатель	
	int count();
	customSP operator=(const customSP& a); // оператор присваивания, увеличивает счетчик
	T operator*(); // перегруженный оператор разыменования
	~customSP(); // деструктор
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
