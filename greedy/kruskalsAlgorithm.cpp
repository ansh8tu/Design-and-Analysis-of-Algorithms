#include<iostream>
#include<algorithm>
using namespace std;

class edge_connecting_vertices
{
	public:
		int first_vertex;
		int second_vertex;
		int weight;
};


bool comparison_of_edges(edge_connecting_vertices first_edge, edge_connecting_vertices second_edge)
{
	return first_edge.weight < second_edge.weight;
}

int parent_of_vertex(int vertex, int* parent) 
{
	if (parent[vertex] == vertex)
	{
		return vertex;
	}

	return parent_of_vertex(parent[vertex], parent);
}

void kruskal_mst(edge_connecting_vertices* ptr, int no_of_vertices) 
{

	int* parent = new int[no_of_vertices];

	for (int i = 0; i < no_of_vertices; i++)
	{
		parent[i] = i;
	}

	edge_connecting_vertices* output = new edge_connecting_vertices[no_of_vertices - 1];

	//declaring a variable j to iterate over ptr to choose n-1 edges
	int j = 0; 

	//declaring a variable track to make sur that n-1 edges have been choosen
	int count = 0;

	while (count < no_of_vertices - 1)
	{
		int parent_of_source = parent_of_vertex(ptr[j].first_vertex, parent);
		int parent_of_destination = parent_of_vertex(ptr[j].second_vertex, parent);

		if (parent_of_source != parent_of_destination) 
		{
			output[count] = ptr[j];
			parent[parent_of_source] = parent[parent_of_destination];
			count++;
		}
		j++;
	}

	// Displaying the minimum spanning tree after the calculations
	for (int i = 0; i < no_of_vertices - 1; i++) 
	{ 
		cout << "The pair of vertex chosen followed by the weight : ";
		cout << " ( "<< output[i].first_vertex << " , " << output[i].second_vertex << " ) " <<" Weight of edge: "<< output[i].weight << endl;

	}

	return;
}

int main() 
{
	int no_of_vertices, no_of_edges;
	cout << "Enter the number of vertices: ";
	cin >> no_of_vertices;

	cout << "Enter the number of edges: ";
	cin >> no_of_edges;

	cout << "\n";

	edge_connecting_vertices* edges = new edge_connecting_vertices[no_of_edges];
	int i = 0;
	while (i < no_of_edges) 
	{
		cout << "Enter the first vertex followed by the second vertex followed by the weight of the edge :";
		cin >> edges[i].first_vertex >> edges[i].second_vertex >> edges[i].weight;
		i++;
	}

	cout << "\n";

	sort(edges, edges + no_of_edges, comparison_of_edges);
	kruskal_mst(edges, no_of_vertices);

	return 0;
}


