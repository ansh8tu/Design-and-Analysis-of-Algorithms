#include<iostream>
#include<algorithm>
using namespace std;


//Defining a structure to store the start time and finish time of various activities
struct list_of_activities
{
    int start_time;
    int finish_time;
};

// Function to sort the finish times of the activities
bool sort_finish_time(list_of_activities a1, list_of_activities a2)
{
    return (a1.finish_time < a2.finish_time);
}

//Function to calculate the max. no. of activities that can be performed 
void efficient_activity_selection(list_of_activities parent_array[], int no_of_activities)
{
    sort(parent_array, parent_array + no_of_activities, sort_finish_time);
    cout << "Selected activities include: \n";

    int i = 0;
    cout << "(" << parent_array[i].start_time << ", " << parent_array[i].finish_time << ")\n";

    // Consider the remaining activities from 1 to n-1 
    for (int j = 1; j < no_of_activities; j++)
    {
        // start time of an activity is greater than or equal to the finish time of previous activity
        if (parent_array[j].start_time >= parent_array[i].finish_time)
        {
            cout << "(" << parent_array[j].start_time << ", " << parent_array[j].finish_time << ") \n";
            i = j;
        }
    }
}

int main()
{
    list_of_activities parent_array[20];
    int no_of_activities;

    cout << "Enter the number of activities that you wish to execute: ";
    cin >> no_of_activities;
    cout << "\n";

    for (int i = 0; i <no_of_activities; i++)
    {
        cout << "Input the start time of activity " << i + 1 << " : ";
        cin >> parent_array[i].start_time;

        cout << "Input the finish time of activity " << i + 1 << " : ";
        cin >> parent_array[i].finish_time;

        cout << "\n";
    }

    //Calling the function to give us the max. number of activities that can be performed
    efficient_activity_selection(parent_array, no_of_activities);

    return 0;
}
