#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;

void insertion_sort(int parent_array[], int no_of_elements)
{

	for (int j = 1; j < no_of_elements; j++)
	{
		int i, temp_value;
		//Storing the value of element at jth in a temp_value
		temp_value = parent_array[j];
		i = j - 1;
		//Loop to compare the values
		while (i >= 0 && parent_array[i] > temp_value)
		{
			parent_array[i + 1] = parent_array[i];
			i = i - 1;
		}
		parent_array[i + 1] = temp_value;
	}
}

void display_output(int parent_array[], int no_of_elements)
{
	int i;
	for (i = 0; i < no_of_elements; i++)
	{
		cout << parent_array[i] << " ";

	}
}

int main()
{
	int no_of_elements, i;

	cout << "Enter the number of elements: ";
	cin >> no_of_elements;

	//Taking input from a file using file handling 
	ifstream file;
	int parent_array[1000];
	file.open("Numbers.txt");

	//
	if (file.fail())
	{
		cout << "Error, can't open file";
	}

	else
	{
		while (!file.eof())
		{
			for (i = 0; i < no_of_elements; i++)
			{
				file >> parent_array[i];
			}
		}
		file.close();
	}

	//Displaying the input array
	cout << "Before implementing Insertion sort: " << "\n";
	display_output(parent_array, no_of_elements);

	auto start1 = std::chrono::high_resolution_clock::now();
	//Calling Insertion sort function to sort the input array
	insertion_sort(parent_array, no_of_elements);
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;

	cout << "\n\nAfter implementing Insertion sort we get: " << "\n";
	display_output(parent_array, no_of_elements);

	std::cout << "\n\nInsertion Sort Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}

