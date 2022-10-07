#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int arr[n];

    int x = arr[n-1];
    
    for(int i = 0; i < n; i++) cin >> arr[i];

    int count = 0;

    for(int i = 1; i < n; i++){
        if(arr[i-1] > arr[i]) count++;
    }
    if(arr[n-1] > arr[0]) count++;

    if(count <= 1) cout << "yes";
    else cout << "no";

    return 0;
}