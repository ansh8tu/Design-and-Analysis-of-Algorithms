#include<iostream>
#include<string>
using namespace std;

int largest_cs_fun(string pattern_1, string pattern_2, int len_pattern_1, int len_pattern_2)
{
    //2d matrix to store values(LCS largest common subsequence)
    int LCS[20][20] = {};

    for (int i = 0; i <= len_pattern_1; i++)
    {
        //length of string 2 is 0
        LCS[i][0] = 0;
    }

    for (int j = 0; j <= len_pattern_2; j++)
    {
        //length of string 1 is 0
        LCS[0][j] = 0; 
    }

    //matrix filling
    for (int i = 1; i <= len_pattern_1; i++)
    {
        for (int j = 1; j <= len_pattern_2; j++)
        {
            //matching condition
            if (pattern_1[i - 1] == pattern_2[j - 1])
            {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }

            //not matches
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    return LCS[len_pattern_1][len_pattern_2];
}


int main()
{
    string pattern_1, pattern_2;

    cout << "Enter the first Pattern : ";
    getline(cin, pattern_1);

    cout << "Enter the second Pattern : ";
    getline(cin, pattern_2);

    //pattern length
    int len_pattern_1 = pattern_1.length();  
    int len_pattern_2 = pattern_2.length();  

    cout << "The length of largest common subsequence is : " << largest_cs_fun(pattern_1, pattern_2, len_pattern_1, len_pattern_2);
    cout << endl;
    return 0;
}
