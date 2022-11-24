#include<bits/stdc++.h>
using namespace std;


int main() {
    
    cout << "Enter number of Nodes : ";
    int m;
    cin >> m;

    int matrix[m+1][m+1];
    memset(matrix, 0, sizeof(matrix));

    cout << "Enter number of edges : ";
    int n;
    cin >> n;

    cout << "Enter edges : \n";
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >>v;
        matrix[u][v] = 1;
        // matrix[v][u] = 1; 
    }

    cout << "Adjacency matrix : \n";

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // adjacents of v1, v2, v3 ... vm
    for(int i = 1; i <= m; i++) {
        cout << "Adjacent of node " << i << " : ";  
        for(int j = 1; j <= m; j++) {
            if(matrix[i][j]) cout << j << " ";
        }
        cout << endl;
    }

    int powMatrix[m+1][m+1][m+1];
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= m; j++) powMatrix[1][i][j] = matrix[i][j];
    }

    for(int i = 2; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= m; k++) {
                int temp = 0;
                for(int l = 1; l <= m; l++) {
                    temp += powMatrix[i-1][j][l]*matrix[l][k];
                }
                powMatrix[i][j][k] = temp;
            }
        }
    }

    for(int i = 2; i <= m; i++) {
        cout << "paths of length " << i << " : \n"; 
        int cnt = 0;
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= m; k++) {
                if(powMatrix[i][j][k]) {
                    cout << "From node " << j << " to " << k << endl;
                    cnt++;
                }
            }
        }
        cout << "\ntotal number of path " << i << " is : " << cnt << endl;
    }

    cout << endl << endl;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= m; k++) {
                cout << powMatrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }


    return 0;
}