#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void BubbleSort(int arr[], int n){

    for(int i = 1; i < n; i++){
        // this is for checking that if after one iteration no values are swapped means the array is already sorted so no need to do furthur iteration
        bool swapped = false;

        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true; 
            }
        }
        // this condn is for checking if array is already sorted 
        // so no need to do extra calculation  so TC: O(N)
        if(swapped == false) break; 
    }
}

void SelectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;

        for(int j = i+1; j < n; j++){

            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

}

void InsertionSort(int arr[], int n){

    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j >= 0; j--){
            if(arr[j] > temp) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int s, int e){

    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // make sure when you dynamically allocates m/m then to delete that m/m also after its use to prevent memory leak
    int *first = new int[len1];
    int *second = new int[len2];

    // copy krdo values ko new array created m
    int k = s;
    for(int i = 0; i < len1; i++) first[i] = arr[k++];
    k = mid + 1;
    for(int i = 0; i < len2; i++) second[i] = arr[k++];

    // merge 2 sorted arrays
    int index1 = 0, index2 = 0;
    k = s;
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }
    while(index1 < len1) arr[k++] = first[index1++];
    while(index2 < len2) arr[k++] = second[index2++];

    delete []first;
    delete []second;
}

void mergeSort(int arr[], int s, int e){

    // base case
    if(s >= e){
        return;
    }
    int mid = s + (e-s)/2;

    // left part sort
    mergeSort(arr, s, mid);

    // right part sort
    mergeSort(arr, mid+1, e);

    // merge krdo dono sorted arrays ko
    merge(arr, s, e);
}

int partition(int arr[], int s, int e){

    int pivot = arr[s];
    int cnt = 0;

    // we'll take out the count of no of elements smaller than pivot
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot) cnt++;
    }

    // place the pivot element at right index
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]); 

    // left and right wala part smbhl lete h
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex){
        // check if any element lesser than pivot in left part
        while(arr[i] <= pivot){ i++;}

        // check if any element greater than the pivot in right part
        while(arr[j] > pivot){j--;}

        // if we reach here means than element doesn't follow the prior condn so need to swap them
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){

    // base case
    if(s >= e) return;

    // partition karenge
    int p = partition(arr, s, e);

    // left part sort krnge
    quickSort(arr, s, p-1);

    // right part sort krnge
    quickSort(arr, p+1, e);
}

int main(){

    int n; cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // BubbleSort(arr, n);
    // SelectionSort(arr, n);
    // InsertionSort(arr, n);
    // mergeSort(arr, 0, n-1);
    quickSort(arr, 0, n-1);
    
    printArray(arr, n);
    
    return 0;
}