#include <iostream>
#include<chrono>
#include<fstream>
using namespace std;

int binary_search(int parent_array[], int leftmost_index, int rightmost_index, int element_to_find)
{

	if (rightmost_index >= leftmost_index)
	{
		//Calculating the value of middle_index
		int middle_index = leftmost_index + (rightmost_index - leftmost_index) / 2;

		//Checking whether the element_to_find is present at the middle_index
		if (parent_array[middle_index] == element_to_find)
			return middle_index;

		//Checking whether the element_to_find is smaller than the middle_index then the element_to_find is present in the left part of array
		if (parent_array[middle_index] > element_to_find)
			return binary_search(parent_array, leftmost_index, middle_index - 1, element_to_find);

		//If none of the above cases qualify then the element_to_find is present in the right part of array
		return binary_search(parent_array, middle_index + 1, rightmost_index, element_to_find);
	}

	//If the element_to_find isn't present in the array then simply return -1
	return -1;
}

//Defining a function to display the elements before linear search
void display_output(int array[], int no_of_elements)
{
	int i;
	for (i = 0; i < no_of_elements; i++)
		cout << array[i] << "  ";
	cout << endl;
}

int main()
{

	int no_of_elements, element_to_find,i;

	cout << "Enter the number of elements: ";
	cin >> no_of_elements;

	//Taking input from a file using file handling 
	ifstream file;
	int parent_array[1000];
	file.open("SortedNumbers.txt");

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
	

	cout << "Array for Binary search: " << "\n";
	display_output(parent_array, no_of_elements);

	cout << "Enter the element that you want to find : ";
	cin >> element_to_find;


	auto start1 = std::chrono::high_resolution_clock::now();
	//Calling binary search function to search the element
	int value = binary_search(parent_array,0, no_of_elements, element_to_find);
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;

	//Conditional statements to check whether the element exists or not
	if (value == -1)
	{
		cout << "Element doesn't exist, try again ";
	}
	else
	{
		cout << "Element is present at index: " << value;
	}
	std::cout << "\nBinary Search Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}

