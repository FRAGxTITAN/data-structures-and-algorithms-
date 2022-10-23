#include <iostream>
using namespace std;

int  maximum_sum(int arr[], int n) {
    int res = arr[0];
    int maxEnding = arr[0];
    
    for(int i=1; i<n; i++) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res,maxEnding);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
   cout << maximum_sum(arr, n);
    
    return 0;
}
