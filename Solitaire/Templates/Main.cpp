#include "stdafx.h"
#include <iostream>
#include "Matrix.cpp"
#include <vector>

//-----------------------FIRST PART---------------------------------------------


void initialise(Matrix<bool>& mat, int& choice)
{
	if (choice == 0)
	{
		for (int x = 0; x < mat.get_nb_rows(); x++)
		{
			for (int y = 0; y < mat.get_nb_cols(); y++)
			{
				mat.set_element(x, y, true);
				if (x < 2 && y < 2) mat.set_element(x, y, false);
				if (x < 2 && y > 4) mat.set_element(x, y, false);
				if (x > 4 && y > 4) mat.set_element(x, y, false);
				if (x > 4 && y < 2) mat.set_element(x, y, false);
			}
		}
	}
	else
	{
		for (int x = 0; x < mat.get_nb_rows(); x++)
		{
			for (int y = 0; y < mat.get_nb_cols(); y++)
			{
				mat.set_element(x, y, true);
				if (x < 2 && y < 2) mat.set_element(x, y, false);
				if (x < 2 && y > 4) mat.set_element(x, y, false);
				if (x > 4 && y > 4) mat.set_element(x, y, false);
				if (x > 4 && y < 2) mat.set_element(x, y, false);
			}
		}
		mat.set_element(1, 1, true);
		mat.set_element(5, 5, true);
		mat.set_element(1, 5, true);
		mat.set_element(5, 1, true);
	}
		
}

Matrix<int> createIndex(Matrix<bool>& mat)
{
	Matrix<int> index(mat.get_nb_rows(), mat.get_nb_cols());
	int counter = 0;

	for (int x = mat.get_nb_rows(); x >= 0; x--)
	{
		for (int y = 0; y < mat.get_nb_cols(); y++)
		{
			if (mat.get_element(x, y) == true)
			{
				index.set_element(x, y, counter);
				counter++;
			}
		}
	}

	return index;
}

Matrix<int> createJumpMatrix(Matrix<bool>& mat, Matrix<int>& index, int& choice)
{


	if (choice == 0)
	{
		Matrix<int> jump(33, 76);
		int jumps = 0;

		for (int x = mat.get_nb_rows(); x >= 0; x--)
		{
			for (int y = 0; y < mat.get_nb_cols(); y++)
			{
				if (mat.get_element(x, y) == true)
				{
					if (mat.get_element(x, y + 2) == true && (y + 2) < mat.get_nb_cols()) //check right
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x, y + 1), jumps, +1);
						jump.set_element(index.get_element(x, y + 2), jumps, -1);
						jumps++;
					}
					if (mat.get_element(x, y - 2) == true && (y - 2) >= 0) //check left
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x, y - 1), jumps, +1);
						jump.set_element(index.get_element(x, y - 2), jumps, -1);
						jumps++;
					}
					if (mat.get_element(x - 2, y) == true && (x - 2) >= 0) //check up
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x - 1, y), jumps, +1);
						jump.set_element(index.get_element(x - 2, y), jumps, -1);
						jumps++;
					}
					if (mat.get_element(x + 2, y) == true && (x + 2) < mat.get_nb_rows()) //check down
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x + 1, y), jumps, +1);
						jump.set_element(index.get_element(x + 2, y), jumps, -1);
						jumps++;
					}
				}
			}
		}
		return jump;
	}
	else
	{
		Matrix<int> jump(37, 92);
		int jumps = 0;

		for (int x = mat.get_nb_rows(); x >= 0; x--)
		{
			for (int y = 0; y < mat.get_nb_cols(); y++)
			{
				if (mat.get_element(x, y) == true)
				{
					if (mat.get_element(x, y + 2) == true && (y + 2) < mat.get_nb_cols()) //check right
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x, y + 1), jumps, +1);
						jump.set_element(index.get_element(x, y + 2), jumps, -1);
						jumps++;
					}
					if (mat.get_element(x, y - 2) == true && (y - 2) >= 0) //check left
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x, y - 1), jumps, +1);
						jump.set_element(index.get_element(x, y - 2), jumps, -1);
						jumps++;
					}
					if (mat.get_element(x - 2, y) == true && (x - 2) >= 0) //check up
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x - 1, y), jumps, +1);
						jump.set_element(index.get_element(x - 2, y), jumps, -1);
						jumps++;
					}
					if (mat.get_element(x + 2, y) == true && (x + 2) < mat.get_nb_rows()) //check down
					{
						jump.set_element(index.get_element(x, y), jumps, +1);
						jump.set_element(index.get_element(x + 1, y), jumps, +1);
						jump.set_element(index.get_element(x + 2, y), jumps, -1);
						jumps++;
					}
				}
			}
		}
		return jump;
	}

	
	
}

int countJumps(Matrix<bool> mat, Matrix<bool> board)
{
	
	int availableJumps = 0;
	
	for (int x = mat.get_nb_rows(); x >= 0; x--)
	{
		for (int y = 0; y < mat.get_nb_cols(); y++)
		{
			if (board.get_element(x, y) == true)
			{
				if (mat.get_element(x, y + 2) == true
					&& board.get_element(x, y + 2) == false
					&& (y + 2) < board.get_nb_cols()
					&& board.get_element(x, y + 1) == true) //check right
				{
					availableJumps++;
				}
				if (mat.get_element(x, y - 2) == true
					&& board.get_element(x, y - 2) == false
					&& (y - 2) >= 0
					&& board.get_element(x, y - 1) == true) //check left
				{
					availableJumps++;
				}
				if (mat.get_element(x - 2, y) == true
					&& board.get_element(x - 2, y) == false
					&& (x - 2) >= 0
					&& board.get_element(x - 1, y) == true) //check up
				{
					availableJumps++;
				}
				if (mat.get_element(x + 2, y) == true
					&& board.get_element(x + 2, y) == false
					&& (x + 2) < board.get_nb_rows()
					&& board.get_element(x + 1, y) == true) //check down
				{
					availableJumps++;
				}
			}
		}
	}
	return availableJumps;
}

void makeJump(Matrix<bool>& mat, Matrix<bool>& board, int& x, int& y, char& direction)
{

	if (board.get_element(x, y) == true)
	{
		if (direction == 'r' 
			&& mat.get_element(x, y + 2) == true 
			&& board.get_element(x, y + 2) == false 
			&& (y + 2) < board.get_nb_cols()
			&& board.get_element(x, y + 1) == true) //check right
		{
			board.set_element(x, y, 0);
			board.set_element(x, y + 1, 0);
			board.set_element(x, y + 2, 1);
			
		}
		else if (direction == 'l' 
			&& mat.get_element(x, y - 2) == true 
			&& board.get_element(x, y - 2) == false 
			&& (y - 2) >= 0
			&& board.get_element(x, y - 1) == true) //check left
		{
			board.set_element(x, y, 0);
			board.set_element(x, y - 1, 0);
			board.set_element(x, y - 2, 1);
		}
		else if (direction == 'u' 
			&& mat.get_element(x - 2, y) == true 
			&& board.get_element(x - 2, y) == false 
			&& (x - 2) >= 0
			&& board.get_element(x - 1, y) == true) //check up
		{
			board.set_element(x, y, 0);
			board.set_element(x - 1, y, 0);
			board.set_element(x - 2, y, 1);
		}
		else if (direction == 'd' 
			&& mat.get_element(x + 2, y) == true 
			&& board.get_element(x + 2, y) == false 
			&& (x + 2) < board.get_nb_rows()
			&& board.get_element(x + 1, y) == true) //check down
		{
			board.set_element(x, y, 0);
			board.set_element(x + 1, y, 0);
			board.set_element(x + 2, y, 1);
		}
		else
		{
			cout << "Think again" << endl;
		}
	}
	else
	{
		cout << "Coordinates are invalid, please try again" << endl;
	}
			
	}

void play(Matrix<bool> m_bool)
{
	Matrix<bool> m_board;
	m_board = m_bool;
	m_board.set_element(3, 3, 0);

	m_board.showClean(m_bool);

	int x, y;
	char direction;

	while (countJumps(m_bool, m_board) > 0)
	{

		cout << "Please type row number between 0 and 6: ";
		cin >> x;
		while (x < 0 || x > 6)
		{
			cout << "Please type row number between 0 and 6: ";
			cin >> x;
		}

		cout << "Please type column number between 0 and 6: ";
		cin >> y;
		while (y < 0 || y > 6)
		{
			cout << "Please type column number between 0 and 6: ";
			cin >> y;
		}

		cout << "Please type direction u, d, r, l : ";
		cin >> direction;
		while (direction != 'u' && direction != 'l' && direction != 'r' && direction != 'd')
		{
			cout << "Please type direction u, d, r, l : \n";
			cin >> direction;
		}

		makeJump(m_bool, m_board, x, y, direction);
		m_board.showClean(m_bool);


	}
}


//-----------------------SECOND PART---------------------------------------------

/*
Vector a holds all the non zero values.
Vector ia holds the index in a of the first non zero value in every row. The last element holds the total
number of non zero elements(size of a).
Vector ja contains the column index in jump matrix of each element of a.
*/
void yale(Matrix<int> jump_mat, vector<int>& a, vector<int>& ia, vector<int>& ja)
{
	bool nzv;
	for (int x = 0; x < jump_mat.get_nb_rows(); x++)
	{
		nzv = true;
		for (int y = 0; y < jump_mat.get_nb_cols(); y++)
		{
			//If non zero store in a and save y in ja
			if (jump_mat.get_element(x, y) != 0)
			{
				a.push_back(jump_mat.get_element(x, y));
				ja.push_back(y);
			}

			//When first non zero value is found on each row, save its index in a (or else a.size()) in ia
			if (nzv == true && jump_mat.get_element(x, y) != 0)
			{
				ia.push_back(a.size() - 1);
				nzv = false;
			}//If no non zero value has been found, end of row has been reached and last element is zero save zero to ia
			else if (nzv == true && y == (jump_mat.get_nb_cols() - 1) && jump_mat.get_element(x, y) == 0)
			{
				ia.push_back(0);
			}
		}
	}
	ia.push_back(a.size());
}

template <typename T>
void turnToVector(Matrix<T>& mat, Matrix<bool>& bl, vector<T>& vec)
{

	for (int x = mat.get_nb_rows(); x >= 0; x--)
	{
		for (int y = 0; y < mat.get_nb_cols(); y++)
		{
			if (bl.get_element(x,y) == true)
			vec.push_back(mat.get_element(x, y));
		}
	}
}

//Check a pagoda to see if it is valid by checking x+y>=z
template <typename T>
bool isValid(Matrix<bool>& mat, Matrix<T>& pagoda, int& xx, int& yy, char& zz)
{
	bool valid = true;

	for (int x = mat.get_nb_rows(); x >= 0; x--)
	{
		for (int y = 0; y < mat.get_nb_cols(); y++)
		{
			if (mat.get_element(x, y) == true && valid == true)
			{
				if (mat.get_element(x, y + 2) == true && (y + 2) < mat.get_nb_cols()) //check right
				{
					if ( pagoda.get_element(x, y) + pagoda.get_element(x, y + 1) < pagoda.get_element(x, y + 2) )
					{
						valid = false;
						xx = x; yy = y; zz = 'r';
					}
				}

				if (mat.get_element(x, y - 2) == true && (y - 2) >= 0) //check left
				{
					if ((pagoda.get_element(x, y) + pagoda.get_element(x, y - 1)) < pagoda.get_element(x, y - 2))
					{
						valid = false;
						xx = x; yy = y; zz = 'l';
					}
				}

				if (mat.get_element(x - 2, y) == true && (x - 2) >= 0) //check up
				{
					if ((pagoda.get_element(x, y) + pagoda.get_element(x - 1, y)) < pagoda.get_element(x - 2, y))
					{
						valid = false;
						xx = x; yy = y; zz = 'u';
					}
				}

				if (mat.get_element(x + 2, y) == true && (x + 2) < mat.get_nb_rows()) //check down
				{
					if ((pagoda.get_element(x, y) + pagoda.get_element(x + 1, y)) < pagoda.get_element(x + 2, y))
					{
						valid = false;
						xx = x; yy = y; zz = 'd';
					}
				}
			}
		}
	}
	return valid;
}

void findPagoda(Matrix<bool>& mat, Matrix<bool>& end, Matrix<bool>& fixed)
{
	int x, y;
	char z;
	bool fixedFull = false;

	Matrix<bool> end2 = end;

	while (isValid(mat, end, x, y, z) == false && fixedFull == false)
	{
		if (z == 'u')
		{
			if (fixed.get_element(x, y) == true)
			{
				end.set_element(x, y, end.get_element(x, y) + 1);
				fixed.set_element(x, y, 0);
			}
			else if (fixed.get_element(x - 1, y) == true)
			{
				end.set_element(x - 1, y, end.get_element(x - 1, y) + 1);
				fixed.set_element(x - 1, y, 0);
			}
			else if (fixed.get_element(x - 2, y) == true)
			{
				end.set_element(x - 2, y, end.get_element(x - 2, y) - 1);
				fixed.set_element(x - 2, y, 0);
			}
		}
		else if (z == 'd')
		{
			if (fixed.get_element(x, y) == true)
			{
				end.set_element(x, y, end.get_element(x, y) + 1);
				fixed.set_element(x, y, 0);
			}
			else if (fixed.get_element(x - 1, y) == true)
			{
				end.set_element(x + 1, y, end.get_element(x + 1, y) + 1);
				fixed.set_element(x + 1, y, 0);
			}
			else if (fixed.get_element(x - 2, y) == true)
			{
				end.set_element(x + 2, y, end.get_element(x + 2, y) - 1);
				fixed.set_element(x + 2, y, 0);
			}
		}
		else if (z == 'r')
		{
			if (fixed.get_element(x, y) == true)
			{
				end.set_element(x, y, end.get_element(x, y) + 1);
				fixed.set_element(x, y, 0);
			}
			else if (fixed.get_element(x, y + 1) == true)
			{
				end.set_element(x, y + 1, end.get_element(x, y + 1) + 1);
				fixed.set_element(x, y + 1, 0);
			}
			else if (fixed.get_element(x, y + 2) == true)
			{
				end.set_element(x, y + 2, end.get_element(x, y + 2) - 1);
				fixed.set_element(x, y + 2, 0);
			}
		}
		else if (z == 'l')
		{
			if (fixed.get_element(x, y) == true)
			{
				end.set_element(x, y, end.get_element(x, y) + 1);
				fixed.set_element(x, y, 0);
			}
			else if (fixed.get_element(x, y - 1) == true)
			{
				end.set_element(x, y - 1, end.get_element(x, y - 1) + 1);
				fixed.set_element(x, y - 1, 0);
			}
			else if (fixed.get_element(x, y - 2) == true)
			{
				end.set_element(x, y - 2, end.get_element(x, y - 2) - 1);
				fixed.set_element(x, y - 2, 0);
			}
		}

	}
	
	
	
}

int main() {


	//-----------------------FIRST PART---------------------------------------------

	int choice;

	do
	{
		cout << "Type 0 for English board or 1 for European board :";
		cin >> choice;
	} while (choice != 0 && choice != 1);
	

	Matrix<bool> m_bool(7, 7);
	initialise(m_bool, choice);

	Matrix<int> m_index = createIndex(m_bool);

	Matrix<int> m_jump = createJumpMatrix(m_bool, m_index, choice);

	play(m_bool);
	cout << "GAME OVER";


	//-----------------------SECOND PART---------------------------------------------



	vector<int> a;
	vector<int> ia;
	vector<int> ja;
	yale(m_jump, a, ia, ja);

	
	Matrix<bool> start;
	Matrix<bool> end(7,7);
	Matrix<int> pagoda(7,7);

	start = m_bool;

	start.set_element(3, 2, 0);
	start.set_element(2, 3, 0);
	start.set_element(3, 3, 0);
	start.set_element(3, 4, 0);
	start.set_element(4, 3, 0);
	end.set_element(3, 2, 1);
	end.set_element(2, 3, 1);
	end.set_element(3, 3, 1);
	end.set_element(3, 4, 1);
	end.set_element(4, 3, 1);

	pagoda.set_element(0, 2, -1);
	pagoda.set_element(0, 4, -1);
	pagoda.set_element(1, 2, 1);
	pagoda.set_element(1, 3, 1);
	pagoda.set_element(1, 4, 1);
	pagoda.set_element(2, 0, -1);
	pagoda.set_element(2, 1, 1);
	pagoda.set_element(2, 3, 1);
	pagoda.set_element(2, 5, 1);
	pagoda.set_element(2, 6, -1);
	pagoda.set_element(3, 1, 1);
	pagoda.set_element(3, 2, 1);
	pagoda.set_element(3, 3, 2);
	pagoda.set_element(3, 4, 1);
	pagoda.set_element(3, 5, 1);
	pagoda.set_element(4, 0, -1);
	pagoda.set_element(4, 1, 1);
	pagoda.set_element(4, 3, 1);
	pagoda.set_element(4, 5, 1);
	pagoda.set_element(4, 6, -1);
	pagoda.set_element(5, 2, 1);
	pagoda.set_element(5, 3, 1);
	pagoda.set_element(5, 4, 1);
	pagoda.set_element(6, 2, -1);
	pagoda.set_element(6, 4, -1);


	findPagoda(m_bool, end, m_bool);

	

	

	

	int out;
	cin >> out;
	return 0;
}