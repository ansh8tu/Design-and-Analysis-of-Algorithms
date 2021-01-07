#include <iostream>
#include <cstdlib>
using namespace std;

class prims_algorithm
{

private:

	int number_of_nodes;
	int weight_of_each_node[10][10] = {}, visited_nodes[10] = {};

public:

	prims_algorithm()
	{
		int i;
		number_of_nodes = 0;
		for (i = 0; i < number_of_nodes; i++)
		{
			visited_nodes[i] = 0;
		}
	}

	void user_input();
	void output_mst();
};

void prims_algorithm::user_input()
{
	int i, j;

	cout << "Input the number of nodes for Prim's Algorithm : ";
	cin >> number_of_nodes;
	cout << "\n";

	cout << "Input the adjacency matrix of order " << number_of_nodes <<" x " << number_of_nodes << " for Prim's Algorithm : ";
	cout << "\n";
	for (i = 0; i < number_of_nodes; i++)
	{
		for (j = 0; j < number_of_nodes; j++)
		{
			cin >> weight_of_each_node[i][j];
		}
	}
}

void prims_algorithm::output_mst()
{
	int i, j, min, k , l , m, total_cost = 0;
	min = 99999;

	for (i = 0; i < number_of_nodes; i++)
	{
		for (j = 0; j < number_of_nodes; j++)
		{
			if (weight_of_each_node[i][j] < min && weight_of_each_node[i][j] != 0)
			{
				min = weight_of_each_node[i][j];
				k = i;
				l = j;
			}
		}
	}

	cout << "\nEdge " << k << "<-->" << l << "having weight: " << min;
	visited_nodes[k] = 1;
	visited_nodes[l] = 1;	
	total_cost = min;
	for (m = 0; m < number_of_nodes - 2; m++)
	{
		min = 99999;
		for (i = 0; i < number_of_nodes; i++)
		{
			if (visited_nodes[i] == 1)		
			{
				for (j = 0; j < number_of_nodes; j++)
				{
					if (visited_nodes[j] != 1)		
					{
						if (weight_of_each_node[i][j] < min && weight_of_each_node[i][j] != 0)
						{
							min = weight_of_each_node[i][j];
							k = i;
							l = j;
						}
					}
				}
			}
		}

		cout << "\nThe Edge " << k << "<--->" << l << " has the weight: " << min;
		visited_nodes[k] = 1;
		visited_nodes[l] = 1;
		total_cost = total_cost + min;

	}
	cout << "\nTotal cost for the Prim's MST is: " << total_cost << endl;
}

int main() 
{
	int input = 0;
	prims_algorithm prims_element;
	do {
		cout << "1. Input the details for Construction of Graph \n2. Perform Prim's Algorithm for MST \n3. Exit\nEnter choice(1, 2 or 3) : ";
		cin >> input;
		switch (input)
		{
		case 1: prims_element.user_input();
		{
			break;
		}
		case 2: prims_element.output_mst();
		{
			break;
		}
		case 3: exit(0);
		default: cout << "Please Enter a valid number(1,2 or 3)";
			break;
		}
	} while (input != 3);
	return 0;
}
