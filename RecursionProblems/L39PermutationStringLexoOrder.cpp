#include <bits/stdc++.h>
using namespace std;

// Method 1 : Using rotate() func.
void permute(string str, string out)
{
	// When size of str becomes 0, out has a permutation (length of out is n)
	if (str.size() == 0)
	{
		cout << out << endl;
		return;
	}

	// One be one move all characters at
	// the beginning of out (or result)
	for (int i = 0; i < str.size(); i++)
	{
		// Remove first character from str and
		// add it to out
		permute(str.substr(1), out + str[0]);

		// Rotate string in a way second character
		// moves to the beginning.
		rotate(str.begin(), str.begin() + 1, str.end());
	}
}

// Method 2: Using swap() method
void solve(vector<int> nums, vector<vector<int>>&ans, int index){
    
    // base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j = index; j < nums.size(); j++){
        swap(nums[index], nums[j]);
        solve(nums, ans, index+1);
        swap(nums[index], nums[j]); // backtracking step to neutralize the string to reach to its original str 
    }
}

int main()
{
	string str = "ABC";
	permute(str, "");
	return 0;
}



// we can directly take out the permutation of a string usign stl func. next_permutation(str.begin(), str.end()); which does the work in O(n) 
// do {
//        cout << str << endl;
//     } while (next_permutation(str.begin(), str.end()));
