#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template <typename T>
class Matrix
{
public:
	Matrix(int nb_rows = default_nb_rows, int nb_columns = default_nb_columns);
	Matrix(const Matrix<T>& src);
	~Matrix();

	// overloaded operators on class
	Matrix<T>& operator=(const Matrix<T>& rhs);

	template <typename E>
	friend ostream& operator<<(ostream& ostr, const Matrix<E>& mtx);

	template <typename E>
	friend Matrix<E> operator*(const Matrix<E>& a, const Matrix<E>& b);

	int get_nb_rows() const { return nb_rows; }
	int get_nb_cols() const { return nb_columns; }
	T get_element(int row, int col) const;
	void set_element(int row, int col, T elem);
	void make_efficient(vector<T>& a, vector<T>& ia, vector<T>& ja);
	void showClean(const Matrix<T>& a);

	// constant elements
	static const int default_nb_rows = 3;
	static const int default_nb_columns = 3;
protected:

	T* cells;
	int nb_rows;
	int nb_columns;
};

//Constractor that accepts row and column number
template <typename T>
Matrix<T>::Matrix(int row, int col):
nb_rows(row), nb_columns(col) {
	cells = new T[nb_rows * nb_columns];
	memset(cells, 0, (nb_rows * nb_columns * sizeof(T)));
}

//Constructor that accepts Matrix and will copy it
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& src):
nb_rows(src.nb_rows), nb_columns(src.nb_columns) 
{
	const int TL = nb_rows * nb_columns;
	cells = new T[TL];
	memcpy_s(cells, (TL * sizeof(T)), src.cells, (TL * sizeof(T)));
	//memcpy(cells, src.cells, TL * sizeof(T)); // same but less safe than memcpy_s
}

template <typename T>
Matrix<T>::~Matrix() {
	delete[] cells;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	if(this == &rhs) return (*this);
	
	// release old memory
	delete[] cells;

	// change dimensions
	nb_rows = rhs.nb_rows;
	nb_columns = rhs.nb_columns;
	const int TL = nb_rows * nb_columns;

	// allocate new memory
	cells = new T[TL];
	memcpy_s(cells, (TL * sizeof(T)), rhs.cells, (TL * sizeof(T)));

	return *this;
}

// friend functions

template <typename E>
ostream& operator<<(ostream& ostr, const Matrix<E>& mtx)
{
	int row = 1;
	ostr << "  ";
	for (int i = 0; i < mtx.nb_columns; ++i)
	{
		ostr << i << " ";
	}
	ostr << "\n";
	ostr << "0 ";

	for (int i = 0; i < mtx.nb_rows * mtx.nb_columns; ++i) {
		if (i % mtx.nb_columns == 0 && i != 0)
		{
			ostr << "\n";
			ostr << row << " ";
			row++;
		}

		if ((mtx.cells[i] >= 0))
		{
			ostr << " " << mtx.cells[i] << " ";
		}
		else
		{
			ostr << mtx.cells[i] << " ";
		}

	}
	ostr << std::endl << std::endl;
	return ostr;
}



template <typename T>
void Matrix<T>::showClean(const Matrix<T>& a) 
{
	int row = 1;
	cout << "  ";
	for (int i = 0; i < a.nb_columns; ++i)
	{
		cout << i << " ";
	}
	cout << "\n";
	cout << "0 ";

	for (int i = 0; i < a.nb_rows * a.nb_columns; ++i) {
		if (i % a.nb_columns == 0 && i != 0)
		{
			cout << "\n";
			cout << row << " ";
			row++;
			
		}
		
		
		if (a.cells[i] == false)
		{
			cout << "  ";
		}
		else
		{
			cout << cells[i] << " ";
		}
		

	}
	cout << std::endl << std::endl;
}

template <typename E>
Matrix<E> operator*(const Matrix<E>& a, const Matrix<E>& b) {

	assert(a.nb_columns == b.nb_rows);

	Matrix<E> result(a.nb_rows, b.nb_columns);

	for(int i = 0; i < a.nb_rows; ++i) {
		for(int j = 0; j < b.nb_columns; ++j) {
			for(int k = 0; k < a.nb_columns; ++k) {
				result.cells[i * result.nb_columns + j] += a.cells[i * a.nb_columns + k] * b.cells[k * b.nb_columns + j];
			}
		}
	}
	return result;
}

template <typename T>
T Matrix<T>::get_element(int row, int col) const {
	return cells[row * nb_columns + col];
}

template <typename T>
void Matrix<T>::set_element(int row, int col, T elem) {
	cells[row * nb_columns + col] = elem;
}

template <typename T>
void Matrix<T>::make_efficient(vector<T>& a, vector<T>& ia, vector<T>& ja)
{
	
}

