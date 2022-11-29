#include<iostream>
using namespace std;


int main() {

    cout << "Enter number of nodes : ";
    int m;
    cin >> m;

    int matrix[m][m];

    cout <<"Enter the matrix : \n";


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int pmatrix[m][m][m];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            pmatrix[0][i][j] = matrix[i][j];
        }
    }

    for(int l = 1; l < m; l++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                int temp = 0;
                for(int k = 0; k < m; k++) {
                    temp += pmatrix[l-1][i][k] * matrix[k][j];
                }
                pmatrix[l][i][j] = temp;
            }
        }
    }

    cout << endl << endl;

    for(int l = 0; l < m; l++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                cout << pmatrix[l][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    return 0;
}