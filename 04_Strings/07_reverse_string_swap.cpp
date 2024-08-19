#include <iostream>
using namespace std;

int main(){
    string str = "Chetan";

    int i = 0, j = 0;

    for(; str[i] != '\0'; i++){}
    i -= 1;
    
    while( i > j){
       char t = str[i];
       str[i] = str[j];
       str[j] = t;
       i--;
       j++;
    }

    cout<<str<<endl;

    return 0;
}