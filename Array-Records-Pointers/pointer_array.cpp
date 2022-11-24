#include<iostream>

using namespace std;

int main() {
    
    cout << "Enter number of groups : ";
    int m;
    cin >> m;

    cout << "Enter number of maximum elements of a group : ";
    int n;
    cin >> n;

    int data[m][n];
    int group[m+1];
    int arr[100];
    group[0] = 0;
    cout << "Enter the data of the matrix : \n";
    int k = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++) {

        for(int j = 0; j < n; j++) {
            cin >> data[i][j];
            if(data[i][j] != 0) {
                arr[k++] = data[i][j];
                cnt++;
            }
        }
        group[i+1] = cnt;
    }

    cout << "Enter the number of group you want to see : ";
    int x;
    cin >> x;
    int first = group[x-1];
    int last = group[x]-1;

    cout << "Group" << x << " : ";
    for(int i = first; i <= last; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
   
    // for(int i = 0; i <= m; i++) cout << group[i] << " ";
    // cout << endl;

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    /*
    1 2 3 4 5 
    0 1 2 3 4 
    0 0 0 3 4 
    1 2 2 2 2

    for group 2
    output : Group 2 : 3 4

    */

    return 0;
}