#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k){

    vector<int> temp(nums.size());

    for(int i = 0; i < nums.size(); i++){
        temp[(i+k)%nums.size()] = nums[i];
    }

    nums = temp;

    for(int i = 0;  i < nums.size(); i++){
        cout << nums[i] << " ";
    }

}

int  main(){

    int n, k; cin >> n >> k;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        nums.push_back(a);
    }

    rotate(nums, k);

    return 0;
}