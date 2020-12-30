#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;

//Function to swap the elements of array 
void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//Used to find out the sorted element after every iteration
int partition(int array[], int leftmost_index, int rightmost_index)
{
	int pivot_element,i,j;
	i = leftmost_index - 1;
	//The element which will be used for all the comparisons is the pivot element(initially considered as the last element of the given array)
	pivot_element = array[rightmost_index];

	//Loop for iterating over the complete left side of the array
	for (j = leftmost_index; j <= rightmost_index - 1; j++)
	{	
		//Condition to sort 
		if (array[j] <= array[rightmost_index])
		{	
			i++;
			swap(array[j], array[i]);
		}
	}
	//After all type of sorting just swap the i+1 th element with the rightmost element so that the specific element gets sorted
	swap(array[i + 1], array[rightmost_index]);
	return i + 1;
}

//Function to implement quick sort
void quick_sort(int array[], int leftmost_index, int rightmost_index)
{

	if (leftmost_index < rightmost_index)
	{
		int sorted_index;
		//The index having sorted element after each iteration is termed as sorted_index
		sorted_index = partition(array, leftmost_index, rightmost_index);
		quick_sort(array, leftmost_index, sorted_index - 1);
		quick_sort(array, sorted_index + 1, rightmost_index);
	}
}

//Display function
void display_output(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
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
	cout << "Before implementing quick sort: " << "\n";
	display_output(parent_array, no_of_elements);

	auto start1 = std::chrono::high_resolution_clock::now();
	//Calling Quick sort function to sort the input array
	quick_sort(parent_array, 0, no_of_elements - 1);
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;

	cout << "\n\nAfter implementing quick sort we get: " << "\n";
	display_output(parent_array, no_of_elements);

	std::cout << "\n\nQuick Sort Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}
