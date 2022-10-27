#include <iostream>
using namespace std;

void reverseStringWordWise(char input[]) {
    int len=0;
    for(len=0;input[len]!='\0';len++);
    int i=0,j= len-1;
    while(i<j){
        char temp= input[i];
        input[i]= input[j];
        input[j]=temp;
        i++;
        j--;
    }
    
    i=0,j=0;
    for(i=0;i<=len;i++){
        if(input[i]==' ' or input[i]=='\0' ){
            int k=i-1;
            while(j<k){
         char temp= input[j];
        input[j]= input[k];
        input[k]=temp;
        j++;
        k--;
            }
            j=i+1;
        }
        
    }
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
