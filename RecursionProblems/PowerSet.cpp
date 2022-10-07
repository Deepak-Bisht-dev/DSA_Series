// This problem also comes with the name subsequence as we take out power set of a string or subsequence they are same

#include <bits/stdc++.h>
using namespace std;

// str : Stores input string
// curr : Stores current subset
// index : Index in current subset, curr
void powerSet(string str, int index = 0, string curr = ""){
	
    int n = str.length(); // This is done to improve the code quality 

	// base case
	if (index == n){
		cout << curr << endl;
		return;
	}
	// include the char
    powerSet(str, index + 1, curr + str[index]);
    // exclude the char
	powerSet(str, index + 1, curr);
    
}

int main()
{
	string str;
    cin >> str;
	powerSet(str);
	return 0;
}
