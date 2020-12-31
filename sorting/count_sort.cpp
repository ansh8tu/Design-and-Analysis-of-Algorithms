#include<iostream>
using namespace std;

int largest_element = 0;

void counting_sort(int parent_array[], int sorted_array[], int no_of_elements)
{
	int counting_elements[40];

	//Initializing the count to 0
	for (int i = 0; i <= largest_element; i++)
	{
		counting_elements[i] = 0;
	}

	//Counting the occurence of any unique element and incrementing the count by 1 each time the element is repeated
	for (int i = 0; i < no_of_elements; i++)
	{
		counting_elements[parent_array[i]] = counting_elements[parent_array[i]] + 1;
	}

	//Storing the cummulative count in order to check how many elements are present before a particular element(<=)
	for (int i = 1; i <= largest_element; i++)
	{
		counting_elements[i] = counting_elements[i] + counting_elements[i - 1];
	}

	//Storing the result in the sorted array and decrementing the count by 1 each time when an element is added 
	for (int i = 0; i < no_of_elements; i++)
	{
		sorted_array[counting_elements[parent_array[i]]] = parent_array[i];
		counting_elements[parent_array[i]] = counting_elements[parent_array[i]] - 1;
	}
}

void display_output(int parent_array[], int no_of_elements)
{
	for (int i =0; i < no_of_elements; i++)
	{
		cout << "Element at index " << i << " is : " << parent_array[i+1] << endl;
	}
}

int main()
{
	int parent_array[40], no_of_elements, sorted_array[40];

	cout << "Enter the size of the array : ";
	cin >> no_of_elements;
	cout << endl;

	for (int i = 0; i < no_of_elements; i++)
	{
		cout << "Enter the elment at index " << i << " : ";
		cin >> parent_array[i];

		if (parent_array[i] > largest_element)
		{
			largest_element = parent_array[i];
		}
	}
	cout << endl;
	counting_sort(parent_array, sorted_array, no_of_elements);
    display_output(sorted_array, no_of_elements);
	cout << endl;

}
