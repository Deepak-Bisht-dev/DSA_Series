#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m; cin >> n >> m;

    int arr1[n], arr2[m];
    int ans[max(n,m)];

    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];

    int  i = n - 1, j = m - 1;
    int carry = 0;
    while(i >= 0 && j >= 0){

        int val1 = arr1[i];
        int val2 = arr2[j];

        int sum = val1 + val2 + carry;

        carry /= 10;
        sum %= 10;


        // we'll save the value in vector becoming complex 
        // using array so, just explanation ahead...

        // first case : when left part is left 

        // second case : when second case is left

        // third case : when carry is there
    }


}