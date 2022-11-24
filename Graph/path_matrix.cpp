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
    // for(int i = 1; i <= m; i++) {
    //     cout << "Adjacent of node " << i << " : ";  
    //     for(int j = 1; j <= m; j++) {
    //         if(matrix[i][j]) cout << j << " ";
    //     }
    //     cout << endl;
    // }

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

    int Br[m+1][m+1];
    memset(Br, 0, sizeof(Br));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= m; k++) {
                Br[j][k] = powMatrix[i][j][k];  
            }   
        }
    }

    int cnt = 0;

    cout << "Path Matrix : \n";
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            cout << Br[i][j] << " ";
            if(Br[i][j] == 0) cnt++;
        }
        cout << endl;
    }
    cout << endl;
    if(cnt == 0) cout << "Strongly Connected!" << endl;
    else cout << "Not Stronlgy Connected! " << endl;
    
    return 0;
}