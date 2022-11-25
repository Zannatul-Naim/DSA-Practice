#include<iostream>

using namespace std;


int main() {

    cout << "Enter number of vertices : ";
    int v;
    cin >> v;

    int matrix[v][v];
    cout << "Enter the matrix : \n";
    int shortest_path_matrix[v][v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cin >> matrix[i][j];
            shortest_path_matrix[i][j] = matrix[i][j];
            
        }
    }

    // calculate shortest path matrix :
    for(int k = 0; k < v; k++) {
        
        cout << endl << endl;
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                cout << shortest_path_matrix[i][j] << " ";
            }
        cout << endl;
        }

        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                shortest_path_matrix[i][j] = shortest_path_matrix[i][j] | (shortest_path_matrix[i][k] && shortest_path_matrix[k][j]);
            }
        }
    }

    cout << "\nShortest path matrix : \n";
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cout << shortest_path_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}