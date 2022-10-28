// Program to find smallest number among three numbers

#include<iostream>

int main()
{
    int a, b, c, small;
    cout << "Enter three numbers : ";
    cin >> a >> b >> c;
  
    small = (a < b) ? (a < c ? a : c) : (b < c ? b : c);   // for finding the smallest value.

    cout << "Smallest value : " << small << endl;
    return 0;
}
