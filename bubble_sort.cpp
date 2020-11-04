#include<iostream>
#include<chrono>
using namespace std;

//Swap function to swap the elements of the array while sorting
void swap(int& x, int& y)
{
	//Declaring a temporary variable to swap the elements
	int temp;
	temp = x;
	x = y;
	y = temp;
}

//Defining the bubble sort function to sort the elements of the array
void bubble_sort(int parent_array[], int no_of_elements)
{
	int i, j;
	//Loop to iterate through the array(passes)
	for (i = 0; i < no_of_elements - 1; i++)
	{
		//Loop to check condition and swap the elements
		for (j = 0; j < no_of_elements - i - 1; j++)
		{
			//if statement to check the condition
			if (parent_array[j] > parent_array[j + 1])
			{
				swap(parent_array[j], parent_array[j + 1]);
			}
		}
	}
}

//Defining a function to display the elements before and after bubble sort
void display_output(int parent_array[], int no_of_elements)
{
	int i;
	for (i = 0; i < no_of_elements; i++)
	{
		cout << parent_array[i] << "\t";
	}
}

int main()
{
	int parent_array[50], no_of_elements, i;

	cout << "Enter the size of array: ";
	cin >> no_of_elements;

	//Taking the input array from the user
	for (i = 0; i < no_of_elements; i++)
	{
		cout << "Enter the element at index " << i + 1 << " : ";
		cin >> parent_array[i];
	}

	//Displaying the input array
	cout << "Before implementing bubble sort: " << "\n";
	display_output(parent_array, no_of_elements);

	auto start1 = std::chrono::high_resolution_clock::now();

	//Calling bubble sort function to sort the input array
	bubble_sort(parent_array, no_of_elements);

	auto finish1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed1 = finish1 - start1;

	cout << "\nAfter implementing bubble sort we get: " << "\n";
	display_output(parent_array, no_of_elements);

	std::cout << "\nBubble sort Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}
