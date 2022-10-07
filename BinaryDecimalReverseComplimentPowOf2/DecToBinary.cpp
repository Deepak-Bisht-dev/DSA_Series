#include<bits/stdc++.h>
using namespace std;

// conversion of a no to it's binary
void DecToBinary(int n){

    int ans = 1;
    int i = 0;

    while(n != 0){

        int bit = n & 1;
        ans = ans + (bit * pow(10, i) );

        n = n >> 1;
        i++;

    }
    cout << "Dec to Binary no is:  " << ans << endl;

}

// conversion of a binary no to its decimal
void BinaryToDec(int n){

    int ans = 0, i = 0;
    while(n != 0){
        int digit = n % 10;
        if(digit == 1){
            ans = ans + pow(2, i);
        }
        n = n / 10;
        i++;
    }

    cout << "Binary to Dec no is: " << ans << endl;

}

// reverse an  integer
void reverse(int n){
    
    int ans = 0;
    while(n != 0){
        int digit = n % 10;

        // this condn for out of bound error
        // like the value of ans is beyond range of int
        if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
            return;
        }

        ans = (ans * 10) + digit;
        n = n/10;
    }

    cout << ans << endl;

}

// Complement of base 10 integer
void complement(int n){

    int temp = n;
    int mask = 0;

    // imp edge case to care of
    if(temp == 0) {
        cout << "1" << endl;
        return;
    }

    while(temp != 0){
        mask = (mask << 1) | 1;
        temp = temp >> 1;
    }
    int ans = (~n) & mask;

    cout << ans << endl;

}

// Check whether the integer is power of 2 or not
void powerOfTwo(int n){

    // if want to do using bitwise in O(1) then
    // if(n & ~(n-1) == n) return true
    
    int ans = 1;
    for(int i = 0; i <= 30; i++){
        
        if(ans == n){
          cout << "Yes" << endl;
          return;  
        } 
        ans = ans * 2;
    }
    cout << "No" << endl;
        
}

int main(){

    int n; cin >> n;

//   DecToBinary(n);
//    BinaryToDec(n);
//    reverse(n);
//   complement(n);
    powerOfTwo(n);
    return 0;
}