#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, char sour, char aux, char dest)
{
    if(n == 1)
    {
        cout<<"move disk "<<n<<" from "<<sour<<" to "<<dest<<endl;
    }
    else{
    tower_of_hanoi(n-1, sour, dest, aux);
    cout<<"move disk "<<n<<" from "<<sour<<" to "<<dest<<endl; 
    tower_of_hanoi(n-1, aux, sour, dest);
    }
}

int main()
{

    int n;
    cout<<"Enter the number of disks: "<<endl;
    cin>>n;
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}
