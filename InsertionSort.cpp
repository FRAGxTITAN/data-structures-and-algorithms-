#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2];
    
    for(int i=0; i<n1; i++) {
        left[i] = arr[low + i];
    }
    
    for(int i=0; i<n2; i++) {
        right[i] = arr[n1 + i];
    }
    
    int i=0, j=0, k=low;
    
    while(i < n1 && j < n2) {
        
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++; k++;
        }
        
        else {
            arr[k] = right[j];
            j++; k++;
        }
    }
    
    while(i < n1) {
        arr[k] = left[i];
        i++; k++;
    }
    
    while(j < n2) {
        arr[k] = right[j];
        j++; k++;
    }
}

void merge_sort(int arr[], int low, int high) {
    if(high > low) {
        int mid = low + (high - low)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid +1 ,high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    merge_sort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout<< arr[i] <<" ";
    }
    return 0;
}
