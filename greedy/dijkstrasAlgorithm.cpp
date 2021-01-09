#include<iostream>
using namespace std;
#define vertex 5  

// min_distance vertex that is not included yet
int min_distance(int distance[], bool set_of_distances[])   
{
	//Taking a large value for min
	int min_dt = 99999, index;               
	for (int i = 0; i < vertex; i++)
	{
		if (set_of_distances[i] == false && distance[i] <= min_dt)
		{
			min_dt = distance[i];
			index = i;
		}
	}
	return index;
}

void dijkstra_algo(int graph[vertex][vertex], int source_vertex) 
{
	int distance[vertex];
	bool set_of_distances[vertex];
	for (int i = 0; i < vertex; i++)                   
	{
		distance[i] = 99999;
		set_of_distances[i] = false;
	}
	//source vertex distance is initialized to 0
	distance[source_vertex] = 0;                                
	for (int i = 0; i < vertex; i++)
	{
		int u = min_distance(distance, set_of_distances);             
		set_of_distances[u] = true;                              
		for (int v = 0; v < vertex; v++)
		{
			if (!set_of_distances[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
				distance[v] = distance[u] + graph[u][v];
		}
	}

	cout << "Vertex\t\tDistance from the source vertex" << endl;
	for (int i = 0; i < vertex; i++)                       /*will print the vertex with their distance from the source to the console */
	{
		char c = 65 + i;
		cout << c << "\t\t" << distance[i] << endl;
	}
}
int main()
{
	int graph[vertex][vertex];

	cout << "Enter the adjacency matrix of order " << vertex << " x " << vertex << " : " << endl;
	for (int i = 0; i < vertex ; i++)
	{
		for (int j = 0; j < vertex; j++)
		{
			cin >> graph[i][j];
		}
	}

	dijkstra_algo(graph, 0);
	return 0;
}




