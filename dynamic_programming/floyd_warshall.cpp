#include <iostream>
using namespace std;

void floyds_algorithm(int parent_array[][10], int no_of_vertices)
{
    int i, j, k;
    for (k = 0; k < no_of_vertices; k++)
    {
        for (i = 0; i < no_of_vertices; i++)
        {
            for (j = 0; j < no_of_vertices; j++)
            {
                if ((parent_array[i][k] * parent_array[k][j] != 0) && (i != j))
                {
                    if ((parent_array[i][k] + parent_array[k][j] < parent_array[i][j]) || (parent_array[i][j] == 0))
                    {
                        parent_array[i][j] = parent_array[i][k] + parent_array[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < no_of_vertices; i++)
    {
        cout << "\nThe Minimum with cost for node :" << i << endl;
        for (j = 0; j < no_of_vertices; j++)
        {
            cout << parent_array[i][j] << "\t";
        }

    }
}
int main()
{
    int parent_array[10][10], no_of_vertices;
    cout << "Enter the number of vertices : ";
    cin >> no_of_vertices;

    cout << "Input the values for adjacency matrix of order "<< no_of_vertices<<" x "<< no_of_vertices<<" : "<<endl;
    for (int i = 0; i < no_of_vertices; i++)
    {
        for (int j = 0; j < no_of_vertices; j++)
        {
            cin >> parent_array[i][j];
        }
    }
    floyds_algorithm(parent_array, no_of_vertices);
}
