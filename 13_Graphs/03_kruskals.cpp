#include<iostream>
using namespace std;

class Set{
    private: 
        int *S;
    
    public:
        Set(int sz){
            S = new int [sz];
            for(int i = 0; i < sz; i++){
                S[i] = -1;
            }
        }

        int Find(int x){
            int n = x;
            while(S[n] > -1){
                n = S[n];
            }
            return n;
        }

        void Union(int u, int v){
            if(S[u] < S[v]){
                S[u] = S[v] + S[u];
                S[v] = u;
            }else{  
                S[v] = S[v] + S[u];
                S[u] = v;
            }
        }
};

int main(){
    int G[3][9] = {
        {1, 1, 2, 2, 3, 4, 7, 5, 5},
        {2, 6, 3, 7, 4, 5, 7, 6, 7},
        {25, 5, 12, 10, 8, 16, 14, 20, 18}
    };

    Set S(8);
    int t[2][6];
    int included[9] = {0};
    int i = 0;

    while(i < 6){
        int least = INT16_MAX;
        int x;

        for(int j = 0; j < 9; j++){
            if(G[2][j] < least && included[j] == 0){
                x = j;
                least = G[2][j];
            }
        }

        included[x] = 1;
        int y = S.Find(G[0][x]);
        int z = S.Find(G[1][x]);

        if(y != z){
            S.Union(y, z);

            t[0][i] = G[0][x];
            t[1][i] = G[1][x];
            i++;
        }
    }

    for(int i = 0; i < 6; i++){
        cout<<"[ "<<t[0][i]<<", "<<t[1][i]<<" ]"<<endl;
    }


    return 0;
}