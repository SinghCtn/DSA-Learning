#include<iostream>
using namespace std;

int I = INT16_MAX;  // Infinite value

void PrimsMST(int G[][8], int n) {
    int near[n];
    for (int i = 0; i < n; i++) {
        near[i] = I;
    }

    int t[2][n-2];  // It should be n-1 edges for an MST

    // Initialize the first edge with the least weight
    int least = I;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (G[i][j] < least) {
                least = G[i][j];
                t[0][0] = i;
                t[1][0] = j;
            }
        }
    }

    near[t[0][0]] = 0;
    near[t[1][0]] = 0;

    // Initialize the near array for all vertices
    for (int i = 1; i < n; i++) {
        if (near[i] != 0) {
            if (G[i][t[0][0]] < G[i][t[1][0]]) {
                near[i] = t[0][0];
            } else {
                near[i] = t[1][0];
            }
        }
    }

    // Prim's algorithm: finding n-1 edges
    for (int i = 1; i < n-2; i++) {
        least = I;
        int k = -1;

        // Find the vertex with the minimum edge
        for (int j = 1; j < n; j++) {
            if (near[j] != 0 && G[j][near[j]] < least) {
                least = G[j][near[j]];
                k = j;
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        // Update the near array
        for (int j = 1; j < n; j++) {
            if (near[j] != 0 && G[j][k] < G[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    // Print the MST edges
    for (int i = 0; i < n-2; i++) {
        cout << "[ " << t[0][i] << ", " << t[1][i] << " ]" << endl;
    }
}

int main() {
    int G[8][8] = {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}
    };

    PrimsMST(G, 8);

    return 0;
}
