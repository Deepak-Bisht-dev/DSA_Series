#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> nums){
    int n = nums.size();
    int nonZero = 0;
    for(int j = 0; j < n; j++){
        if(nums[j] != 0){
            swap(nums[j], nums[nonZero]);
            nonZero++;
        }
    }

    cout << n << endl;

    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){

    int n; cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        nums.push_back(a);
    }

    moveZeroes(nums);

    return 0;
}