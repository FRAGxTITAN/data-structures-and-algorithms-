#include <iostream>
using namespace std;

int find_Majority_Element(int arr[], int n) {
   int res = 0, count = 1;
  
  for(int i=0; i<n; i++) {
      
    if(arr[i] == arr[res])
        count++;
    
    else
        count--;
        
    if(count == 0) {
        count = 1;
        res = i;
    }   
  }
  return arr[res];
} 
int main()
{
   int n;
   cin>>n;
   
   int arr[n];
   
   for(int i=0; i<n; i++) {
       cin>>arr[i];
   }
   
   cout << find_Majority_Element(arr, n);

    return 0;
}
