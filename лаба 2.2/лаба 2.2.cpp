#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <complex>

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key;
}
int menu()
{
	while (true)
	{
		std::cout << "\n1.Perform math operations\n2.Exit\n";
		int key = get_key();
		if (key >= '1' && key <= '2')
			return key;
	}
}
int menu_matematical_operation()
{
	while (true)
	{
		std::cout << "\n1.matrix addition\n2.subtraction of matrices\n3.matrix multiplication\n4.multiplication by a number\n5.division by number\n6.comparison of matrices\n7.index appeal\n8.finding the trace of a matrix\n";
		int key = get_key();
		if (key >= '1' && key <= '8')
			return key;
	}
}
int menu_type()
{
	while (true)
	{
		std::cout << "What type will the matrix data be?\n1.int\n2.double\n3.float\n4.complex double\n5.complex float\n";
		int key = get_key();
		if (key >= '1' && key <= '5')
			return key;
	}
}

template <class T>
void input_values(matrix<T>& v)
{
	int row = 0, col = 0;
	do
	{
		std::cout << "Input the number of rows : ";
		std::cin >> row;
	} while (row <= 0);
	do
	{
		std::cout << "Input the number of columns : ";
		std::cin >> col;
	} while (col <= 0);
	v.set_col(col);
	v.set_row(row);
	std::cout << "Input values : \n";
	std::cin >> v;
}

template <class T>
void matematical_operation(matrix<T> a, matrix<T> b)
{
	try
	{
		std::cout << "Input 2 matrix: \n";
		input_values(a);
		std::cout << a;
		input_values(b);
		std::cout << b;
		std::cout << "\n1 matrix: " << std::endl << a;
		std::cout << "\n2 matrix: " << std::endl << b;
		int choose = menu_matematical_operation();
		switch (choose)
		{
		case '1':
		{
			std::cout << "Result:" << std::endl << a + b;
		}
		break;
		case '2':
		{
			std::cout << "Result:" << std::endl << a - b;
		}
		break;
		case '3':
		{
			std::cout << "Result:" << std::endl << a * b;
		}
		break;
		case '4':
		{
			T c;
			int type = 0;
			std::cout << "Do you want to work with 1 or 2 matrix?" << std::endl;
			std::cin >> type;
			std::cout << "Input the number:";
			std::cin >> c;
			if (type == 1)
			{
				std::cout << "\n1 matrix: " << std::endl << a;
				std::cout << "Result:" << std::endl << a * c << std::endl;
			}
			if (type == 2)
			{
				std::cout << "\n2 matrix: " << std::endl << b;
				std::cout << "Result:" << std::endl << b * c << std::endl;
			}
		}
		break;
		case '5':
		{
			T c;
			int type = 0;
			std::cout << "Do you want to work with 1 or 2 matrix?" << std::endl;
			std::cin >> type;
			std::cout << "Input the number:";
			std::cin >> c;
			if (type == 1)
			{
				std::cout << "\n1 matrix: " << std::endl << a;
				std::cout << "Result:" << std::endl << a / c << std::endl;
			}
			if (type == 2)
			{
				std::cout << "\n2 matrix: " << std::endl << b;
				std::cout << "Result:" << std::endl << b / c << std::endl;
			}
		}
		break;
		case '6':
		{
			if (a == b)
			{
				std::cout << "Matrices are equal\n" << std::endl;
			}
			if (a != b)
			{
				std::cout << "Matrices are not equal\n" << std::endl;
			}
		}
		break;
		case '7':
		{
			std::cout << "Do you want to work with 1 or 2 matrix?" << std::endl;
			int type = 0;
			std::cin >> type;
			std::cout << "Enter which element of the matrix you want to find\n";
			int x, y;
			if (type == 1)
			{
				std::cout << "\n1 matrix: " << std::endl << a;
				std::cout << "Input x";
				std::cin >> x;
				std::cout << "Input y";
				std::cin >> y;
				std::cout << "Result:" << a(x, y) << std::endl;
			}
			if (type == 2)
			{
				std::cout << "\n2 matrix: " << std::endl << b;
				std::cout << "Input x";
				std::cin >> x;
				std::cout << "Input y";
				std::cin >> y;
				std::cout << "Result:" << b(x, y) << std::endl;
			}

		}
		break;
		case '8':
		{
			std::cout << "Do you want to work with 1 or 2 matrix? " << std::endl;
			T c;
			int type = 0;
			std::cin >> type;
			if (type == 1)
			{
				std::cout << "\n1 matrix: " << std::endl << a;
				c = a.finding_a_trace();
				std::cout << "Result:" << c << std::endl;
			}
			if (type == 2)
			{
				std::cout << "\n2 matrix: " << std::endl << b;
				c = b.finding_a_trace();
				std::cout << "Result:" << c << std::endl;
			}
		}
		break;
		default:
			break;
		}
	}
	catch (std::exception err)
	{
		std::cerr << "error: " << err.what() << std::endl;
	}
}
void type_matrix()
{
	int choose = menu_type();
	switch (choose)
	{
	case '1':
	{
		matrix<int> a, b;
		matematical_operation(a, b);

	}
	break;
	case '2':
	{
		matrix<double> a, b;
		matematical_operation(a, b);
	}
	break;
	case '3':
	{
		matrix<float> a, b;
		matematical_operation(a, b);

	}
	break;
	case '4':
	{
		matrix<std::complex<double>> a, b;
		matematical_operation(a, b);
	}
	break;
	case '5':
	{
		matrix<std::complex<float>> a, b;
		matematical_operation(a, b);
	}
	break;
	default:
		break;
	}
}


int main()
{
	bool f = true;
	while (f)
	{
		int choose = menu();
		switch (choose)
		{
		case '1':
		{
			type_matrix();
		}
		break;
		case '2':
		{
			f = false;
		}
		break;
		default:
			break;
		}
	}
	return 0;
}
