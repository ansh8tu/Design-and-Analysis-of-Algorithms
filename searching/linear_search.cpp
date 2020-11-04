#include <iostream>
#include<chrono>
using namespace std;

//Defining a function named as linear_search
int linear_search(int parent_array[], int no_of_elements, int element_to_find)
{
    int i;
    for (i = 0; i < no_of_elements; i++)
    {
        //conditional statement to check whether the element exists or not
        if (parent_array[i] == element_to_find)
        {
            return i;
        }
    }
    return -1;
}

//Defining a function to display the elements before linear search
void display_output(int parent_array[], int no_of_elements)
{
	int i;
	for (i = 0; i < no_of_elements; i++)
	{
		cout << parent_array[i] << "\t";
	}
	cout<<endl;
}

int main()
{
	int parent_array[50], no_of_elements, element_to_find,i;

	cout << "Enter the size of array: ";
	cin >> no_of_elements;

	//Taking the input array from the user
	for (i = 0; i < no_of_elements; i++)
	{
		cout << "Enter the element at index " << i << " : ";
		cin >> parent_array[i];
	}

	//Displaying the input array
	cout << "The array of the input elements: " << "\n";
	display_output(parent_array, no_of_elements);

       //Element that we are going to search
	cout << "Enter the element that you wish to search for: ";
	cin >> element_to_find;

	auto start1 = std::chrono::high_resolution_clock::now();

	//Calling linear search function to search the element
	int value = linear_search(parent_array, no_of_elements,element_to_find);

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

	std::cout << "\n Linear Search Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}

