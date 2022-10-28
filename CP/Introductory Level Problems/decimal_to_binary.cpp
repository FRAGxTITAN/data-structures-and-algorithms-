#include <iostream>
using namespace std;

int main()

{

	int dec, bin[16], i = 0, j = 0;	//dec and bin to store number and its binary equivalent and i and j for index maintaining.

	cout << "Enter a decimal number :";

	cin >> dec;
  cout << "\n";
	while (dec > 0)	//calculating the binary equivalent and storing it in the array

	{
		bin[i] = dec % 2;
		dec = dec / 2;
    ++i;
	}

	cout << "Binary Equivalent:";
	
	for (j = i - 1; j >= 0; --j)
    cout << bin[j];
  
  cout << "\n";
	
	return 0;

}
