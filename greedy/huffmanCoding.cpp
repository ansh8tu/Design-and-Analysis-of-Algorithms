#include <iostream> 
#include<algorithm>
using namespace std;

#define MAX_HIEGHT 100 

// node of tree using struct
struct node_min_heap 
{
	char info;
	unsigned frequency_of_info;
	struct node_min_heap* left, * right;
};

//min heap using struct
struct min_heap
{
	unsigned size_min_heap;
	unsigned capacity_min_heap;
	struct node_min_heap** array;
};

//new min heap node
struct node_min_heap* newNode(char info, unsigned frequency_of_info)
{
	struct node_min_heap* temp = (struct node_min_heap*)malloc(sizeof(struct node_min_heap));
	temp->left = temp->right = NULL;
	temp->info = info;
	temp->frequency_of_info = frequency_of_info;
	return temp;
}

//min heap creation
struct min_heap* min_heap_create(unsigned capacity)
{
	struct min_heap* minHeap= (struct min_heap*)malloc(sizeof(struct min_heap));
	minHeap->size_min_heap = 0;
	minHeap->capacity_min_heap = capacity;
	minHeap->array = (struct node_min_heap**)malloc(minHeap->capacity_min_heap * sizeof(struct node_min_heap*));
	return minHeap;
}

//swapping two min heap nodes
void swap_node_min_heap(struct node_min_heap** node_a,struct node_min_heap** node_b)
{
	struct node_min_heap* temp_var = *node_a;
	*node_a = *node_b;
	*node_b = temp_var;
}

// heapify
void min_heapify_fun(struct min_heap* minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size_min_heap && minHeap->array[left]->frequency_of_info < minHeap->array[smallest]->frequency_of_info)
	{
		smallest = left;
	}
	if (right < minHeap->size_min_heap && minHeap->array[right]->frequency_of_info < minHeap->array[smallest]->frequency_of_info)
	{
		smallest = right;
	}
	if (smallest != idx) 
	{
		swap_node_min_heap(&minHeap->array[smallest],&minHeap->array[idx]);
		min_heapify_fun(minHeap, smallest);
	}
}

//size of heap - one
int check_size(struct min_heap* minHeap)
{
	return (minHeap->size_min_heap == 1);
}

// min value extraction
struct node_min_heap* extractMin(struct min_heap* minHeap)
{
	struct node_min_heap* temp = minHeap->array[0];
	minHeap->array[0]= minHeap->array[minHeap->size_min_heap - 1];
	--minHeap->size_min_heap;
	min_heapify_fun(minHeap, 0);
	return temp;
}

// inserting a new node 
void insert_in_min_heap(struct min_heap* minHeap,struct node_min_heap* minHeapNode)
{
	++minHeap->size_min_heap;
	int i = minHeap->size_min_heap - 1;
	while (i && minHeapNode->frequency_of_info < minHeap->array[(i - 1) / 2]->frequency_of_info)
	{
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

// min heap
void buildMinHeap(struct min_heap* minHeap)
{
	int n = minHeap->size_min_heap - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
	{
		min_heapify_fun(minHeap, i);
	}
}

// display function
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		cout << arr[i];
	}
	cout << "\n";
}

//leaf node
int isLeaf(struct node_min_heap* root)
{

	return !(root->left) && !(root->right);
}

// min heap of given characters
struct min_heap* createAndBuildMinHeap(char info[], int frequency_of_info[], int size)
{
	struct min_heap* minHeap = min_heap_create(size);
	for (int i = 0; i < size; ++i)
	{
		minHeap->array[i] = newNode(info[i], frequency_of_info[i]);
	}
	minHeap->size_min_heap = size;
	buildMinHeap(minHeap);
	return minHeap;
}

// huffman tree
struct node_min_heap* buildHuffmanTree(char info[], int frequency_of_info[], int size)
{
	struct node_min_heap* left, * right, * top;

	//min heap of same size as characters
	struct min_heap* minHeap = createAndBuildMinHeap(info, frequency_of_info, size);

	//size of heap is one
	while (!check_size(minHeap)) 
	{
		//selecting min frequency
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		
		//#- internal node not used, create a new internal node with freq= sum of two nodes frequencies
		top = newNode('#', left->frequency_of_info + right->frequency_of_info);
		top->left = left;
		top->right = right;
		insert_in_min_heap(minHeap, top);
	}
	//root node is the remaining node
	return extractMin(minHeap);
}

// display codes
void display_codes(struct node_min_heap* root, int parent_array[], int top)
{
	if (root->left) 
	{
		parent_array[top] = 0;
		display_codes(root->left, parent_array, top + 1);
	}
	if (root->right) 
	{
		parent_array[top] = 1;
		display_codes(root->right, parent_array, top + 1);
	}
	if (isLeaf(root)) 
	{
		cout << root->info << ": ";
		printArr(parent_array, top);
	}
}

// build & traverse 
void huffman_code(char data[], int frequency_of_info[], int size)
{
	// Construct Huffman Tree 
	struct node_min_heap* root = buildHuffmanTree(data, frequency_of_info, size);
	// display huffman code
	int arr[MAX_HIEGHT], top = 0;
	display_codes(root, arr, top);
}


int main()
{
	char parent_array[20] = {};
	int freq_array[20] = {}, no_of_characters, i;

	cout << "Enter the number of characters used in code : ";
	cin >> no_of_characters;

	for (i = 0; i < no_of_characters; i++)
	{
		cout << "Enter the character Number " << i + 1 << " : ";
		cin >> parent_array[i];
	}

	for (i = 0; i < no_of_characters; i++)
	{
		cout << "Enter the frequency of character Number " << i + 1 << " : ";
		cin >> freq_array[i];
	}
	huffman_code(parent_array, freq_array, no_of_characters);
	return 0;
}

