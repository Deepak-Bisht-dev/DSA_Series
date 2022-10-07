#include<bits/stdc++.h>
using namespace std;

// Approach 1: which is taking O(n.m)
// By basically selecting a element and running two loops
void findArrayIntersection(int arr1[], int arr2[], int n, int m){

    vector<int> ans;

    for(int i = 0; i < n; i++){
        int element = arr1[i];

        for(int j = 0; j < m; j++){

            // this is not optimised as TC : O(m.n)
            // to optimise this it is given in que that array are in non decreasing fashion
            if(element < arr2[j]) break;
            
            if(element == arr2[j]){
                ans.push_back(element);
                arr2[j] = -1;
                break;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    } 
    cout << endl;    

}

// Approach 2 : we'll be doing in max(m,n) TC by using two pointer approach
void ArrayIntersection(int arr1[], int arr2[], int n, int m){

    int i = 0, j = 0;
    vector<int> ans;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++; j++;
        }
        else if(arr1[i] < arr2[j]) i++;
        else j++;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    } 
    cout << endl;
}

int main(){

    int n, m; cin >> n >> m;
    int arr1[n], arr2[m];

    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];

    // findArrayIntersection(arr1, arr2, n, m);
    ArrayIntersection(arr1, arr2, n, m);

    return 0;
}