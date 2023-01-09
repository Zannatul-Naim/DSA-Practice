#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, char src, char aux, char dest) {
    if(n == 1)
    {
        cout << "move disk " << n << " from " << src << " to " << dest << endl;
    } else {  // recursive call
        tower_of_hanoi(n-1, src, dest, aux);
        cout << "move disk " << n << " from " << src << " to " << dest << endl; 
        tower_of_hanoi(n-1, aux, src, dest);
    }
}

int main()
{
    int n;
    cout << "Enter the number of disks: " << endl;
    cin >> n;
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}
