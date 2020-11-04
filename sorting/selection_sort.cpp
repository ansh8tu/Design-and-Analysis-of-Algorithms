// C++ program for implementation of selection sort
#include <iostream>
#include<chrono>
using namespace std;

//Swap function to swap the elements of the array while sorting
void swap(int &x, int &y)
{
    //Declaring a temporary variable to swap the elements
    int temp;
    temp= x;
    x = y;
    y = temp;
}

void selection_sort(int parent_array[], int no_of_elements)
{
    int i, j, min_element;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < no_of_elements - 1; i++)
    {
        //Considering first element to be minimum and then finding the min element from the rest of subarray
        min_element = i;
        for (j = i + 1; j < no_of_elements; j++)
        {
            //Checking the condition using for loop
            if (parent_array[j] < parent_array[min_element])
            {
                min_element = j;
            }
        }
        // Swapping the minimum element with the first element
        swap(parent_array[min_element], parent_array[i]);
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
	cout << "Before implementing selection sort: " << "\n";
	display_output(parent_array, no_of_elements);

	auto start1 = std::chrono::high_resolution_clock::now();

	//Calling selection sort function to sort the input array
	selection_sort(parent_array,no_of_elements-1);

    	auto finish1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed1 = finish1 - start1;

	cout << "\nAfter implementing selection sort we get: " << "\n";
	display_output(parent_array, no_of_elements);

    	std::cout << "\nSelection Sort Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}

