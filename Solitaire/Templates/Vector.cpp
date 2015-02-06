#include "stdafx.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector 
{
public:
	void push(T const&);	  // push element 
	void pop();               // pop element 
	int get_size();           // get number of elements
	T get_element(int x) const;     // get element in place x
	void set_element(int x, T elem);  //set element in place x
	T top() const;            // return top element 
	bool empty() const{	return elems.empty(); } // return true if empty.

protected:
	vector<T> elems;     // elements

};


template <typename T>
int Vector<T>::get_size()
{
	return elems.size();
}

template <typename T>
T Vector<T>::get_element(int x) const
{
	return elems[x];
}

template <typename T>
void Vector<T>::set_element(int x, T elem)
{
	elems[x] = elem;
}


template <typename T>
void Vector<T>::push(T const& elem)
{
	// append copy of passed element 
	elems.push_back(elem);
}

//Prepei na ftiaksw method gia set kai get

template <typename T>
void Vector<T>::pop()
{
	if (elems.empty()) {
		throw out_of_range("Vector<>::pop(): empty Vector");
	}
	// remove last element 
	elems.pop_back();
}

template <typename T>
T Vector<T>::top() const
{
	if (elems.empty()) {
		throw out_of_range("Vector<>::top(): empty Vector");
	}
	// return copy of last element 
	return elems.back();
}