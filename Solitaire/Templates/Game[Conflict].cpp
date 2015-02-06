#include "stdafx.h"
#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"





int main() 
{

	/*Matrix<bool> m_int(7,7);
	m_int.set_element(5, 5, true);

	m_int.initialize();
	m_int.print_board();
	

	Vector<int> v_int;
	v_int.push(7);
	v_int.push(5);

	cout << v_int.get_element(0) << endl;
	cout << v_int.get_element(1) << endl;

	v_int.set_element(0, 3);
	cout << v_int.get_element(0) << endl;*/


	char a;
	for (int i = 0; i<255; i++)
	{
		a = (char)i;
		cout << a << ", ";
	}


	

	return 0;
}