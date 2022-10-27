#include <iostream>
using namespace std;

// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
// You need to find and return that number which is unique in the array/list.

int findUnique(int *arr, int size)
{
    int a= arr[0];
    for(int i=1;i<size;i++){
        a=a^arr[i];
    }
    return a;
}

int main()
{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		cout << findUnique(input, size) << endl;

	return 0;
}
