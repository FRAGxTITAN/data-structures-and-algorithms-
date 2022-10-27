#include <iostream>
using namespace std;

//binary to decimal conversion
void binaryToDecimal(string str){
    int base = 1;
    int ans= 0;
    int l= str.length();
    for(int i=l-1; i>=0;i--){
        ans= ans + ((int)(str[i]-'0')*base);
        base = base*2;
    }
    cout<<ans;
}

int main(){
    string str;
    cin>>str;
    binaryToDecimal(str);
    return 0;
}
