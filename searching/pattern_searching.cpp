#include<iostream> 
#include<chrono>
using namespace std;

void pattern_search(char* pattern, char* comp_word)
{
    // Declaring and defining two variables to store the size of complete word and pattern respectively
    int pattern_length = strlen(pattern);
    int comp_word_length = strlen(comp_word);

    //Loop for shifting the pattern
    for (int i = 0; i <= comp_word_length - pattern_length; i++)
    {
        int j;

        //loop for pattern
        for (j = 0; j < pattern_length; j++)
        {
            
            if (comp_word[i + j] != pattern[j])
            {
                break;
            }
        }

        //Condition for pattern 
        if (j == pattern_length)
        {
            cout << "Pattern found at index " << i << endl;
            cout << "The length of pattern is: " << pattern_length << endl;
        }
    }
}


int main()
{
    //Declaring array of character type to store word and pattern
    char comp_word[40], pattern[20];

    cout << "Input a complete word to search for pattern: ";
    cin >> comp_word;
    cout << "Input a pattern to search from the same word: ";
    cin >> pattern;

    auto start1 = std::chrono::high_resolution_clock::now();
    pattern_search(pattern, comp_word);
    auto finish1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = finish1 - start1;
    std::cout << "\nPattern Printing Time Elapsed: " << elapsed1.count() << "s\n";
    return 0;
}

