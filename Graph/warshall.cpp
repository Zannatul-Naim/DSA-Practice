/*

1 0 1 0
0 1 0 1
0 0 1 1
1 1 0 0

*/

#include<iostream>
using namespace std;

int matrix[20][20];

int main() {

    cout << "Enter number of nodes : ";
    int m;
    cin >> m;

    int matrix[m][m];

    cout << "Enter matrix : " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix (p[0]) is : \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int k = 0; k < m; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                matrix[i][j] = matrix[i][j]?matrix[i][j]:(matrix[i][k]&&matrix[k][j]);
            }
        }
    }

    cout << "Path matrix (p[4]) is : \n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}