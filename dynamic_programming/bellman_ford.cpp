/*
 * C++ Program to Implement Bellmanford Algorithm
 */
#include<iostream>
using namespace std;

struct node
{
    int cost_in_operation;
    int value_stored;
    int path_of_vertex;
}parent_array[6];

//Adding an edge
void adding_edge(int parent_array[][6], int source_vertex, int destination_vertex, int cost_of_action)
{
    parent_array[source_vertex][destination_vertex] = cost_of_action;
    return;
}

//Function for bellman ford
void bellman_ford(int array[][6])
{
    int i, j, k, c = 0, temp;
    parent_array[0].cost_in_operation = 0;
    parent_array[0].path_of_vertex = 0;
    parent_array[0].value_stored = 0;

    //Initializing with infinite cost
    for (i = 1; i < 6; i++)
    {
        parent_array[i].path_of_vertex = 0;
        parent_array[i].cost_in_operation = 9999;
        parent_array[i].value_stored = 0;
    }

    while (c < 6)
    {
        int min = 999;
        for (i = 0; i < 5; i++)
        {
            if (min > parent_array[i].cost_in_operation && parent_array[i].value_stored == 0)
            {
                min = parent_array[i].cost_in_operation;
            }
            else
            {
                continue;
            }
        }
        for (i = 0; i < 6; i++)
        {
            if (min == parent_array[i].cost_in_operation && parent_array[i].value_stored == 0)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        temp = i;
        for (k = 0; k < 6; k++)
        {
            if (array[temp][k] + parent_array[temp].cost_in_operation < parent_array[k].cost_in_operation)
            {
                parent_array[k].cost_in_operation = array[temp][k] + parent_array[temp].cost_in_operation;
                parent_array[k].path_of_vertex = temp;
            }
            else
            {
                continue;
            }
        }
        parent_array[temp].value_stored = 1;
        c++;
    }
    cout << "Cost in Operation" << "\t\t" << "Source Node for the same" << endl;
    for (j = 0; j < 6; j++)
    {
        cout << parent_array[j].cost_in_operation << "\t\t\t\t\t" << parent_array[j].path_of_vertex << endl;
    }
}
int main()
{
    int n, parent_array[6][6], c = 0, i, j, cost_of_edge;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            parent_array[i][j] = 9999;
        }
    }

    while (c < 8)
    {
        cout << "Input the source vertex followed destination vertex and cost of edge: \n";
        cin >> i >> j >> cost_of_edge;
        adding_edge(parent_array, i, j, cost_of_edge);
        c++;
    }

    bellman_ford(parent_array);
}
