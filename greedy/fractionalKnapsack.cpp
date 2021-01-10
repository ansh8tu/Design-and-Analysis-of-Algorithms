#include<iostream> 
#include<algorithm>
using namespace std;

//Designing a structure to store the weight and profit for each item
struct Object 
{
	int profit;
	int	weight;
} parent_array[20];

// function to sort item on the basis of profit/weight ratio
bool Comparison_function( Object a, Object b)
{
	double r1 = (double)a.profit / a.weight;
	double r2 = (double)b.profit / b.weight;
	return r1 > r2;
}

//Function to implement the same Knapsack algorithm
double fractionalKnapsack(struct Object parent_array[], int max_weight_of_knapsack, int capacity)
{
	sort(parent_array, parent_array + capacity, Comparison_function);

	int present_weight = 0;
	double final_result = 0.0;

	// A for loop to loop through all the objects  
	for (int i = 0; i < capacity; i++)
	{
		// Complete addition of item
		if (present_weight + parent_array[i].weight <= max_weight_of_knapsack) {
			present_weight += parent_array[i].weight;
			final_result += parent_array[i].profit;
			cout << "Object "<< i+1<< " completely in the bag with current profit : "<< final_result << endl;
			cout << endl;
		}

		// Fractional addition of item
		else 
		{
			int part_left = max_weight_of_knapsack - present_weight;
			if (part_left == 0)
			{
				break;
			}

			else
			{
				final_result += parent_array[i].profit * ((double)part_left / parent_array[i].weight);
				cout << "Object " << i + 1 << " partially in the bag with current profit : " << final_result << endl;
				cout << endl;
				break;
			}		
		}
	}
	return final_result;
}


int main()
{
	
	int max_weight, no_of_objects;
	Object parent_array[20];

	cout << "Enter the maximum weight of knapsack : ";
	cin >> max_weight;

	cout << "Enter the number of objects that you wish to insert : ";
	cin >> no_of_objects;

	cout << "\n";

	// Input the weight and profit of each object from the user
	for (int i = 0; i < no_of_objects; i++)
	{
		cout << "Enter the Credentials for Object No. " << i + 1 << endl;

		cout << "Enter Weight : ";
		cin >> parent_array[i].weight;

		cout << "Enter profit : ";
		cin >> parent_array[i].profit;

		cout << endl;
	}

	cout << "The maximum profit earned with these objects is = " << fractionalKnapsack(parent_array, max_weight, no_of_objects)<<endl;
	cout << "\n";
	return 0;
}

