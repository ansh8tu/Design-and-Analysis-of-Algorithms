#include<iostream>
#include<fstream>
#include<chrono>
#include<string>
using namespace std;

void merge(int parent_array[], int leftmost_index, int middle_index, int rightmost_index)
{
	//Declaring the vaiables i,j,k for iterating over the elements of subarray sub_1 and sub_2
	int i, j, k;

	//Adding 1 at the last as leftmost_index starts from 0
	int sub_1_elements = middle_index - leftmost_index + 1;
	int sub_2_elements = rightmost_index - middle_index;

	//Declaring an array sub_1 and sub_2 to copy the left and right side elements of parent_array[]
	int sub_1[1000];
	int sub_2[1000];

	//Using a for loop to copy elements of parent loop to left subarray
	//Note: Writing sub_1[i] = parent_array[i]; doesn't makes any sense(leftmost_index is constant(0 mostly))
	for (i = 0; i < sub_1_elements; i++)
	{
		sub_1[i] = parent_array[leftmost_index + i];
	}

	//Using a for loop to copy elements of parent loop to right subarray
	//Note: Similarly writing sub_1[j] = parent_array[j]; doesn't makes any sense(j starts from 0 but we have to start from mid+1)
	for (j = 0; j < sub_2_elements; j++)
	{
		sub_2[j] = parent_array[middle_index + 1 + j];
	}

	//Initializing i,j and k
	i = 0, j = 0; k = leftmost_index;

	//Merging the elements into the parent array
	while (i < sub_1_elements && j < sub_2_elements)
	{
		if (sub_1[i] <= sub_2[j])
		{
			parent_array[k++] = sub_1[i++];
		}

		else
		{
			parent_array[k++] = sub_2[j++];
		}
	}

	//Iterating over the left over elements in any of the two subarrays and adding them back to parent array
	while (i < sub_1_elements)
	{
		parent_array[k++] = sub_1[i++];
	}

	while (j < sub_2_elements)
	{
		parent_array[k++] = sub_2[j++];
	}
}



//Declaring a function for merge sort
void merge_sort(int parent_array[], int leftmost_index, int rightmost_index)
{

	if (leftmost_index < rightmost_index)
	{
		int middle_index = (leftmost_index + rightmost_index) / 2;
		merge_sort(parent_array, leftmost_index, middle_index);
		merge_sort(parent_array, middle_index + 1, rightmost_index);
		merge(parent_array, leftmost_index, middle_index, rightmost_index);
	}
}

//Function to display the output and input array
void display_output(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	int no_of_elements,i;

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
	cout << "Before implementing merge sort: " << "\n";
	display_output(parent_array, no_of_elements);

	auto start1 = std::chrono::high_resolution_clock::now();
	//Calling Merge sort function to sort the input array
	merge_sort(parent_array, 0, no_of_elements -1);
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;

	cout << "\n\nAfter implementing merge sort we get: " << "\n";
	display_output(parent_array, no_of_elements);

	std::cout << "\n\nMerge Sort Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}
