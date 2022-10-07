#include<bits/stdc++.h>
using namespace std;

long long int sqrtBinarySearch(int n){

    int s = 0, e = n;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;

    while(s <= e){
        long long int square = mid * mid;
        if(square == n) return mid;
        if(square < n){
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;

        mid = s + (e-s)/2;
    }
    return ans;
}

// this func is for getting the decimal values as well which we require for more precised ans, for getting the square root of a no.
double morePrecision(int n, int precision, int tempSol){

    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i < precision; i++){
        // as it is becoming 0.1 then 0.01 then 0.01 which precision times the value
        factor = factor/10; 

        for(double j = ans; j*j < n; j = j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){

    int n; 
    cout << "Enter the number: ";
    cin >> n;

    int tempSol = sqrtBinarySearch(n);
    cout << tempSol << endl;
    cout << "Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}