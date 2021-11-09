#pragma once
#include <iostream>
#include <complex>

template <typename T>
class matrix
{
private:
	int _row;
	int _col;
	T** _data;
	
public:

	matrix();
	matrix(const int row, const int col);
	matrix(const matrix& c);
	~matrix();
	int get_row() const;
	int get_col() const;
	void set_col(const int col);
	void set_row(const int rows);
	T& operator () (const int row, const int col);
	T operator () (const int row, const int col) const;
	void operator = (const matrix& c);
	matrix operator + (const matrix& c) const;
	matrix operator - (const matrix& c) const;
	matrix operator * (const matrix& c) const;
	matrix operator * (const T a) const;
	matrix operator / (const T a) const;
	bool operator == (const matrix& c);
	bool operator != (const matrix& c);
	T finding_a_trace() const;
};


template<class T>
matrix<T>::matrix()
{
	_row = 0;
	_col = 0;
	_data = NULL;
}
template<class T>
matrix<T>::matrix(const int row, const int col)
{

	_row = row;
	_col = col;
	_data = new T * [_row];
	for (int i = 0; i < _row; i++)
	{
		_data[i] = new T[_col]();
	}
}
template<class T>
matrix<T>::matrix(const matrix& c)
{
	_row = c._row;
	_col = c._col;
	_data = new T * [_row];
	for (int i = 0; i < _row; i++)
	{
		_data[i] = new T[_col];
	}
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			_data[i][j] = c._data[i][j];
		}
	}
}
template<class T>
matrix<T>::~matrix()
{
	for (int i = 0; i < _col; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
}
template<class T>
int matrix<T>::get_row() const
{
	return _row;
}
template<class T>
int matrix<T>::get_col() const
{
	return _col;
}
template<class T>
void matrix<T>::set_col(const int col)
{
	_col = col;
	_data = new T * [_col];
}

template<class T>
void matrix<T>::set_row(const int row)
{
	_row = row;
	for (int i = 0; i < _col; i++)
	{
		_data[i] = new T[_row]();
	}
}
template<class T>
T& matrix<T> :: operator() (const int row, const int col)
{
	if (col >= _col || row >= _row || col < 0 || row < 0)
	{
		throw std::logic_error("no such index exists");
	}
	return _data[row][col];
}
template<class T>
T matrix<T> :: operator()(const int row, const int col) const
{
	if (col >= _col || row >= _row || col < 0 || row < 0)
	{
		throw std::logic_error("no such index exists");
	}
	return _data[row][col];
}
template<class T>
void matrix<T>:: operator = (const matrix& c)
{
	for (int i = 0; i < _row; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
	_row = c._row;
	_col = c._col;
	_data = new T * [_row];
	for (int i = 0; i < _row; i++)
	{
		_data[i] = new T[_col];
	}
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			_data[i][j] = c._data[i][j];
		}
	}
}
template<class T>
matrix<T> matrix<T> :: operator +  (const matrix& c) const
{
	if (_col != c._col || _row != c._row)
	{
		throw std::logic_error("matrices of different sizes cannot be stacked");
	}

	matrix res(_row, _col);
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			res._data[i][j] = _data[i][j] + c._data[i][j];
		}
	}
	return res;
}
template<class T>
matrix<T> matrix<T> :: operator -  (const matrix& c) const
{
	if (c._col != _col || c._row != _row)
	{
		throw std::logic_error("matrices of different sizes cannot be subtracted");
	}

	matrix res(_row, _col);
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			res._data[i][j] = _data[i][j] - c._data[i][j];
		}
	}
	return res;
}

template<class T>
matrix<T> matrix<T> :: operator * (const matrix& c) const
{
	if (_col != c._row)
	{
		throw std::logic_error("the number of rows of the first matrix is not equal to the number of columns of the second");
	}

	matrix res(_row, c._col);

	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < c._col; j++)
		{
			res._data[i][j] = 0;
			for (int k = 0; k < _col; k++)
			{
				res._data[i][j] += _data[i][k] * c._data[k][j];
			}
		}
	}
	return res;
}

template<class T>
matrix<T> matrix<T> :: operator * (const T a) const
{
	matrix<T> res(_row, _col);
	for (int i = 0; i < _col; i++)
	{
		for (int j = 0; j < _row; j++)
		{
			res._data[i][j] = _data[i][j] * a;
		}
	}
	return res;
}

template<class T>
matrix<T> matrix<T> :: operator / (const T a) const
{
	matrix<T> res(_row, _col);
	for (int i = 0; i < _col; i++)
	{
		for (int j = 0; j < _row; j++)
		{
			res._data[i][j] = _data[i][j] / a;
		}
	}
	return res;
}

template<class T>
bool matrix<T> :: operator == (const matrix& c)
{
	if (_row == c._row && _col == c._col)
	{
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				if (_data[i][j] != c._data[i][j])
					return false;
			}
		}
		return true;
	}
	return false;
}

template<class T>
bool matrix<T> :: operator != (const matrix& c)
{
	if (_row == c._row && _col == c._col)
	{
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				if (_data[i][j] != c._data[i][j])
					return true;
			}
		}
		return false;
	}
	return true;
}

template<class T>
T matrix<T>::finding_a_trace() const
{
	if (_row != _col)
	{
		throw std::logic_error("matrix is not square");
	}
	T a = 0;
	for (int i = 0; i < _col; i++)
	{
		a += _data[i][i];
	}
	return a;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const matrix<T>& a)
{
	for (int i = 0; i < a.get_row(); i++)
	{
		for (int j = 0; j < a.get_col(); j++)
		{
			out << a(i, j) << " ";
		}
		out << std::endl;
	}
	return out;
}
template<class T>
inline std::istream& operator>>(std::istream& in, matrix<T>& a)
{
	for (int i = 0; i < a.get_row(); i++)
	{
		for (int j = 0; j < a.get_col(); j++)
		{
			std::cout << "[" << i << "][" << j << "] : ";
			in >> a(i, j);
		}
	}
	return in;
}

inline std::istream& operator>>(std::istream& in, matrix<std::complex <float>>& a)
{
	for (int i = 0; i < a.get_row(); i++) 
	{
		for (int j = 0; j < a.get_col(); j++) 
		{
			float real = 0, imag = 0;
			std::cout << "[" << i << "][" << j << "]" << std::endl;
			std::cout << "Input real part: ";
			std::cin >> real;
			std::cout << "Input imagine part: ";
			std::cin >> imag;
			a(i, j) = { real, imag };
		}
	}
	return in;
}

inline std::istream& operator>>(std::istream& in, matrix<std::complex <double>>& a)
{
	for (int i = 0; i < a.get_row(); i++) 
	{
		for (int j = 0; j < a.get_col(); j++) 
		{
			double real = 0, imag = 0;
			
			std::cout << "[" << i << "][" << j << "]" << std::endl;
			std::cout << "Input real part: ";
			std::cin >> real;
			std::cout << "Input imagine part: ";
			std::cin >> imag;
			a(i, j) = { real, imag};
		}
	}
	return in;
}
