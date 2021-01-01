#include<iostream>
#include<algorithm>
using namespace std;

int knapsack_fun(int no_of_elements, int weight_of_knapsack, int weight_of_element[], int profit_of_element[])
{
    int i, j, knapsack[10][10] = {};

    //no item
    for (j = 0; j <= weight_of_knapsack; j++)
    {
        knapsack[0][j] = 0;
    }

    //no profit 
    for (i = 0; i <= no_of_elements; i++)
    {
        knapsack[i][0] = 0;
    }

    //filling rest of the matrix
    for (i = 1; i <= no_of_elements; i++)
    {
        for (j = 1; j <= weight_of_knapsack; j++)
        {
            //check if profit increases on including the object or not
            if (weight_of_element[i - 1] <= j)
            {
                knapsack[i][j] = max(knapsack[i - 1][j], profit_of_element[i - 1] + knapsack[i - 1][j - weight_of_element[i - 1]]);
            }

            //item not included
            else
            {
                knapsack[i][j] = knapsack[i - 1][j];
            }
        }
    }
    return knapsack[no_of_elements][weight_of_knapsack];
}

int main()
{
    int no_of_elements, weight_of_knapsack, result;
    int weight_of_element[20] = {}, profit_of_element[20] = {};

    cout << "Enter the number of elements that you wish to include in knapsack : ";
    cin >> no_of_elements;

    cout << "Enter the maximum weight that the Knapsack can hold : ";
    cin >> weight_of_knapsack;
    
    cout << endl;

    for (int i = 0; i < no_of_elements; i++)
    {
        cout << "Enter the weight of the element number " << i + 1 << " : ";
        cin >> weight_of_element[i];

        cout << "Enter the profit of the element number " << i + 1 << " : ";
        cin >> profit_of_element[i];

        cout << endl;

    }

    result = knapsack_fun(no_of_elements, weight_of_knapsack, weight_of_element, profit_of_element); 
    cout << "The maximum profit that you can earn with these elements is : "  << result;

    return 0;
}


