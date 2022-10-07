#include <bits/stdc++.h>
using namespace std;

// func to find all the possible combination of those digits given
void findCombinations(vector<char> keypad[], 
                      int input[], string res, int index, int n)
{
    // If processed every digit of key, print result
    if (index == n) {
        cout << res << " ";
        return;
    }

    // Stores current digit
    int digit = input[index]; // if we take the input as string value here we'll have to extract that like ->
    // int digit = input[index - '0'] otherwise we'll get the ascii value

    // Size of the list corresponding to current digit
    int len = keypad[digit].size();

    // One by one replace the digit with each character in the
    // corresponding list and recur for next digit
    for (int i = 0; i < len; i++) {
        res.push_back(keypad[digit][i]);
        findCombinations(keypad, input, res , index + 1, n);
        res.pop_back(); // this is backtracking step

        // if we don't want to do this with backtracking what we can do is while doing the recursion call include the keypad[digit][i] in res.... So, no need to do push & pop operation
        // findCombinations(keypad, input, res + keypad[digit][i], index + 1, n);
    }
}

int main()
{
    // Given mobile keypad
    vector<char> keypad[] =
    {
        {}, {},        // 0 and 1 digit don't have any characters associated
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}
    };

    // Given input array
    int input[] = { 2, 3};
  
    // Size of the array
    int n = sizeof(input)/sizeof(input[0]);

    // Function call to find all combinations
    findCombinations(keypad, input, string(""), 0, n );

    return 0;
}