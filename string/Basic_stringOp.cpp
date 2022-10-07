#include<bits/stdc++.h>
using namespace std;

void reverse(char name[], int n){
    int s = 0; int e = n-1;

    while(s < e){
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[]){
    int count = 0;
    for(int i = 0; name[i] !='\0'; i++){
        count++;
    }

    return count;
}

bool CheckPalindrome(char a[], int n){
    int s = 0; int e = n-1;
    while(s <= e){
        if(a[s] != a[e]) return 0;

        else {
            s++; e--;
        }
    }
    return 1;
}

char getMaxOccCharacter(string s){

    int arr[26] = {0};

    //create an array of count of characters
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        //lowercase
        int number = 0;
        if(ch >= 'a' && ch <= 'z') number = ch - 'a';
        else number = ch - 'A'; // uppercase

        arr[number]++;
    }

    int maxi = -1, ans = 0;
    for(int i = 0; i < 26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }

    char finalAns = 'a' + ans;
    return finalAns;

}

int main(){

/*
    char name[20];
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is: ";
    cout << name << endl;

    int len = getLength(name);
    cout << "Length of string is : " << len << endl;

    cout << "The reversed string is: " ;
    reverse(name, len);
    cout << name  << endl;

    cout << "Palindrome or not: " << CheckPalindrome(name, len) << endl; 
*/

    string s; cin >> s;

    cout << getMaxOccCharacter(s) << endl;

    return 0;
}