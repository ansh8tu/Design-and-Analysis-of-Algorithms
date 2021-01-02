#include<iostream>
#include<limits.h>
using namespace std;

int MatrixChainMultiplication(int parent_array[], int no_of_matrices)
{
    int m[10][10];
    int i, j, k, chain_length, no_of_multiplications;

    for (i = 1; i < no_of_matrices; i++)
    {
        //in case of single matrix number of multiplications are zero
        m[i][i] = 0;         
    }

    for (chain_length = 2; chain_length < no_of_matrices; chain_length++)
    {
        for (i = 1; i < no_of_matrices - chain_length + 1; i++)
        {
            j = i + chain_length - 1;
            m[i][j] = 9999;  
            for (k = i; k <= j - 1; k++)
            {
                no_of_multiplications = m[i][k] + m[k + 1][j] + parent_array[i - 1] * parent_array[k] * parent_array[j];
                if (no_of_multiplications < m[i][j])
                {
                    //updating less number of multiplications
                    m[i][j] = no_of_multiplications;    
                }
            }
        }
    }
    return m[1][no_of_matrices - 1];   
}

int main()
{
    int no_of_matrices, parent_array[10];
    cout << "Input the number of matrices that you wish to multiply : ";
    cin >> no_of_matrices;
    no_of_matrices++;

    for (int i = 0; i < no_of_matrices; i++)
    {
        cout << "Input the dimension d" << i << " : ";
        cin >> parent_array[i];
    }

    cout << "Minimum number of multiplications is " << MatrixChainMultiplication(parent_array, no_of_matrices);
    return 0;
}
