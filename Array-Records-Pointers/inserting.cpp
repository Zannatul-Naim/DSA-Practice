// #include<iostream>
// #include<math.h>
// using namespace std;

// int main() {
    
//     int a[10] = {4, 6, 23, 45, 55, 58, 60};
//     // insert item 54

//     cout << "Before inserting : ";
//     for(int i = 0; i < 7; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;

//     int size = sizeof(a) / sizeof(int);
//     // cout << size << endl;
//     int i;
//     for(i = 6; i >= 0; i--) {
//         if(a[i] >= 54) a[i+1] = a[i];
//         else break; 
//     }
//     a[i] = 54;

//     cout << "After inserting : ";
//     for(int i = 0; i < 8; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//     // insert karim to position n
//     int pos;
//     cout << "Enter a position : ";
//     cin >> pos;

//     string names[10] = {"naim", "rahim", "ashraful", "shakil", "sayeed", "main", "ashik"};
    
//     cout << "Before inserting : ";
//     for(int i = 0; i < 7; i++) cout << names[i] << " ";
//     cout << endl;

//     int i;
//     for(i = 7; i >=  pos; i--) {
//         names[i+1] = names[i];
//     }
//     names[i] = "karim";

//     cout << "After inserting : ";
//     for(int i = 0; i < 8; i++) cout << names[i] << " ";

//     return 0;
// }


// #include<iostream>
// using namespace std;

// int main() {
//     // insert 99 to position n
//     int pos;
//     cout << "Enter a position : ";
//     cin >> pos;

//     int a[10] = {5, 67, 9, 78, 60, 123, 45, 12};

//     cout << "Before Inserting : ";
//     for(int i = 0; i < 9; i++) cout << a[i] << " ";
//     cout << endl;

//     int i;
//     for(i = 8; i >= pos; i--) {
//         a[i+1] = a[i];
//     }
//     a[i] = 99;

//     cout << "Before Inserting : ";
//     for(int i = 0; i < 10; i++) cout << a[i] << " ";
//     cout << endl;

//     return 0;
// }


#include<iostream>

using namespace std;
int size = 0;

int main() {
    
    // insert rarim to a sorted array

    string names[10] = {"Ashik", "Basir", "Devil", "Hasir", "Naim", "Shakil", "Titi", "Zood"};
    

    for(int i = 0; names[i] != "\0"; i++) size++;

    cout << "Before inserting : ";
    for(int i = 0; i < size; i++) cout << names[i] << " ";
    cout << endl;

    int i;
    for(i = size-1; i >= 0; i--) {
        if(names[i].compare("Rahim") >= 0) names[i+1] = names[i];
        else break;
    }
    names[i+1] = "Rahim";
    size++;

    cout << "After inserting : ";
    for(int i = 0; i < size; i++) cout << names[i] << " ";
    cout << endl;

    return 0;
}
