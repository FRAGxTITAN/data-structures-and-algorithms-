#include <iostream>
using namespace std;
int pairSum(int *input, int size, int x)
{
	int count=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(input[i]+input[j]==x && (i!=j)){
                count++;
            }
        }
    
    }
    return count/2;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}
