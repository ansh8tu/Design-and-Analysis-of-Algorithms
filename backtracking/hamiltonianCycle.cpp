#include<iostream>
using namespace std;

void display_hamiltonian_cycle(int path[], int no_of_vertices)
{
    cout << "The Hamiltonian cycle is as follows : \n";
    for (int i = 0; i < no_of_vertices; i++)
    {
        cout << path[i];
    }

    //complete cycle
    cout << path[0];
    cout << "\n";
}

bool safety_condition(int no_of_vertices, bool graph[10][10], int traversing_path[], int position)
{
   //adjacent vertex
    if (graph[traversing_path[position - 1]][no_of_vertices] == 0)
    {
        return false;
    }

    //vertex already included
    for (int i = 0; i < position; i++)
    {
        if (traversing_path[i] == no_of_vertices)
        {
            return false;
        }
    }
    return true;
}

//main solving function
bool cycle_function(bool graph[10][10], int traversing_path[], int pos, int no_of_vertices)
{
    //all vertices included
    if (pos == no_of_vertices)
    {
        if (graph[traversing_path[pos - 1]][traversing_path[0]] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //trying to add more vertices
    for (int i = 1; i < no_of_vertices; i++)
    {
        //checking if vertex can be added or not
        if (safety_condition(i, graph, traversing_path, pos))
        {
            traversing_path[pos] = i;
            //recursive calling for rest of the graph
            if (cycle_function(graph, traversing_path, pos + 1, no_of_vertices) == true)
            {
                return true;
            }
            //don't add vertex condition fails
            traversing_path[pos] = -1;
        }
    }
    //no further addition
    return false;
}

//bactrack function returns false if no hamiltonian path exists else return true and print
bool cycle_condition(bool graph[10][10], int no_of_vertices)
{
    int* path = new int[no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        path[i] = -1;
    }

    //taking 0 as first vertex
    path[0] = 0;
    if (cycle_function(graph, path, 1,no_of_vertices) == false)
    {
        cout<<"\nNo Hamiltonian Cycle exists! ";
        return false;
    }

    display_hamiltonian_cycle(path, no_of_vertices);
    return true;
}


int main()
{
    int no_of_vertices;
    bool graph[10][10];

    cout << "Enter the number of vertices : ";
    cin >> no_of_vertices;

    cout << "Enter the adjacency matrix of order " << no_of_vertices << " x " << no_of_vertices << " : " << endl;
    for (int i = 0; i < no_of_vertices; i++)
    {
        for (int j = 0; j < no_of_vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    cycle_condition(graph, no_of_vertices);

    return 0;
}
