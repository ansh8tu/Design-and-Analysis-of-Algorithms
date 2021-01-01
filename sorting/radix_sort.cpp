#include<iostream>
using namespace std;

//function to get the largest element from the parent array
int largest_element(int parent_array[], int no_of_elements)
{
    int maximum_right_now = parent_array[0];

    for (int i = 1; i < no_of_elements; i++)
    {
        if (parent_array[i] > maximum_right_now)
        {
            maximum_right_now = parent_array[i];
        }
    }

    return maximum_right_now;
}

void counting_sort(int parent_array[], int no_of_elements, int digit_count_factor)
{
    int sorted_array[40] = { 0 }, counting_elements[40] = { 0 }, i;

    //For loop to count the number of digits
    for (i = 0; i < no_of_elements; i++)
    {
        counting_elements[(parent_array[i] / digit_count_factor) % 10] = counting_elements[(parent_array[i] / digit_count_factor) % 10] + 1;
    }

    //The range is from 0-9 for decimal number system so that's why we'll terminate the loop for i>=10
    for (i = 1; i < 10; i++)
    {
        counting_elements[i] = counting_elements[i] + counting_elements[i - 1];
    }

    //For loop to get the sorted array
    for (i = no_of_elements - 1; i >= 0; i--)
    {
        sorted_array[counting_elements[(parent_array[i] / digit_count_factor) % 10] - 1] = parent_array[i];
        counting_elements[(parent_array[i] / digit_count_factor) % 10] = counting_elements[(parent_array[i] / digit_count_factor) % 10] - 1;
    }

    //For loop to store the sorted array back to the original array i.e. parent_array
    for (i = 0; i < no_of_elements; i++)
    {
        parent_array[i] = sorted_array[i];
    }

}

//Function to implement radix sort
void radix_sort(int parent_array[], int no_of_elements)
{
    int digit_count_factor, max_element;
    max_element = largest_element(parent_array, no_of_elements);

    //for loop to basically call the counting sort function based on the no. of digits of the largest number 
    for (digit_count_factor = 1; max_element / digit_count_factor > 0; digit_count_factor *= 10)
    {
        counting_sort(parent_array, no_of_elements, digit_count_factor);
    }

}

void display_output(int parent_array[], int no_of_elements)
{
    for (int i = 0; i < no_of_elements; i++)
    {
        cout << "Element at index " << i << " is : " << parent_array[i] << endl;
    }
}

int main()
{
    int no_of_elements, parent_array[20];

    cout << "Enter the number of elements: ";
    cin >> no_of_elements;
    cout << endl;
   
    for (int i = 0; i < no_of_elements; i++)
    {
        cout << "Enter the element at index " << i << " : ";
        cin >> parent_array[i];
    }

    cout << endl;
    radix_sort(parent_array, no_of_elements);
    display_output(parent_array, no_of_elements);
    cout << endl;

    return 0;
}
