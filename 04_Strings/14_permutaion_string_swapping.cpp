#include <iostream>
using namespace std;

void Perm(string s, int l, int h){
    if(l == h){
        cout<<s<<endl;
    }else{
        for(int i = l; i <= h; i++){
            swap(s[i], s[l]);
            Perm(s, l+1, h);
            swap(s[i], s[l]);
        }
    }
}

int main(){
    string str = "ABC";
    Perm(str, 0, 2);

    return 0;
}