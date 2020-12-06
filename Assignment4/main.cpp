#include <iostream>
#include "matrix.h"

using namespace std;

void Displaymenu()
{
	cout << "==================================================" << endl;
	cout << "                     Matrix" << endl;
	cout << "==================================================" << endl;
	cout << "     1. Matrix Multiplication" << endl;
	cout << "     2. Right Scalar Multiplication" << endl;
	cout << "     3. Left Scalar Multiplication" << endl;
	cout << "     4. Matrix Assignment" << endl;
}

int main()
{

	Displaymenu();
	Matrix matrixA, matrixB;
	float scalar;
	int YourChoice;

	cout << "Enter your choice(1~4):";
	cin >> YourChoice;
	cout << endl;

	switch (YourChoice)
	{
		//Matrix Multiplication
	case 1:
		cin >> matrixA;
		cout << endl;
		cin >> matrixB;
		cout << endl << "Result: " << matrixA * matrixB << endl;
		break;
		//Right Scalar Multiplication
	case 2:
		cin >> matrixA;
		cout << endl;
		cout << "Scalar: ";
		cin >> scalar;
		cout << endl << "Result: " << matrixA * scalar << endl;
		break;
		//Left Scalar Multiplication
	case 3:
		cout << "Scalar: ";
		cin >> scalar;
		cout << endl;
		cin >> matrixA;
		cout << endl << "Result: " << scalar * matrixA << endl;
		break;
		//Matrix Assignment
	case 4:
		cin >> matrixA;
		matrixB = matrixA;
		cout << endl << "Display Matrix B: " << matrixB << endl;
		break;
	}
	return 0;
}