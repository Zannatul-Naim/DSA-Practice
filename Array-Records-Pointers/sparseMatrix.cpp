#include<iostream>
using namespace std;

int main() {
    
    int sparseMatrix[4][5] = {
        {1, 2, 0, 4, 0},
        {0, 5, 6, 0, 0},
        {0, 0, 2, 3, 0},
        {1, 0, 0, 8, 0}
    };

    int size = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            if(sparseMatrix[i][j]) size++;
        }
    }

    int compressedMatrix[3][size];
    int k = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            if(sparseMatrix[i][j]) {
                compressedMatrix[0][k] = i;  // storing rows
                compressedMatrix[1][k] = j; // storing cols
                compressedMatrix[2][k] = sparseMatrix[i][j];  // storing values
                k++;
            }
        }
    }


    // printing the compressed matrix...

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < size; j++) {
            cout << compressedMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

