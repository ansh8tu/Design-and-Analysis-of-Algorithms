#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int Matrix_1[10][10], Matrix_2[10][10], Product_Matrix[10][10], i, j;
	int p1, p2, p3, p4, p5, p6, p7;

	cout<<"Input the elements of first 2x2 matrix:\n";

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cout << "Input the element at " << "[ " << i << " ]" << " [ " << j << " ] : ";
			cin >> Matrix_1[i][j];
		}
	}

	cout << "\n";

	cout<<"Input the elements for second 2x2 matrix:\n";

	for (i = 0; i <2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cout << "Input the element at " << "[ " << i << " ]" << " [ " << j << " ] : ";
			cin >> Matrix_2[i][j];
		}
	}

	cout << "\n";

	// Strassen's multipliation calculations
	p1 = (Matrix_1[0][0] + Matrix_1[1][1]) * (Matrix_2[0][0] + Matrix_2[1][1]);
	p2 = (Matrix_1[1][0] + Matrix_1[1][1]) * Matrix_2[0][0];
	p3 = Matrix_1[0][0] * (Matrix_2[0][1] - Matrix_2[1][1]);
	p4 = Matrix_1[1][1] * (Matrix_2[1][0] - Matrix_2[0][0]);
	p5 = (Matrix_1[0][0] + Matrix_1[0][1]) * Matrix_2[1][1];
	p6 = (Matrix_1[1][0] - Matrix_1[0][0]) * (Matrix_2[0][0] + Matrix_2[0][1]);
	p7 = (Matrix_1[0][1] - Matrix_1[1][1]) * (Matrix_2[1][0] + Matrix_2[1][1]);

	// Actual resultant matrix elements
	Product_Matrix[0][0] = p1 + p4 - p5 + p7;
	Product_Matrix[0][1] = p3 + p5;
	Product_Matrix[1][0] = p2 + p4;
	Product_Matrix[1][1] = p1 - p2 + p3 + p6;

	//Resultant Matrix
	cout<<"\nThe product of these two matrices using Strassen's Multiplication will be : \n";

	for (i = 0; i < 2; i++) 
	{
		cout << "\n";
		for (j = 0; j < 2; j++)
		{
			cout<< Product_Matrix[i][j]<<"\t";
			
		}
	}
	cout << "\n";
	return 0;
}
