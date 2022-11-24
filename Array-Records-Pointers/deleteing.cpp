// #include<iostream>
// using namespace std;

// int binary_search(string str[], string name, int low, int high) {
    
//     while(low <= high) {
//         int mid = (low+high)/2;
//         // cout << str[mid] << " ";
//         if(str[mid].compare(name) == 0) return mid;
//         else if(str[mid].compare(name) > 0) high = mid-1;
//         else if(str[mid].compare(name) < 0) low = mid+1;
        
//     }
//     return -1;
// }

// int main() {
    
//     // Delete karim from a sorted array

//     string names[10] = {"Ashik", "Basir", "Devil", "Evil", "Hasir", "Karim", "Naim", "Titi", "Zood"};
//     int size = 0;
//     for(int i = 0; names[i] != "\0"; i++) size++;
//     cout << size << endl;
//     int index = binary_search(names, "Karim", 0, size-1);

//     cout << "Before : ";
//     for(int i = 0; i < size; i++) {
//         cout << names[i] << " ";
//     }
//     cout << endl;


//     if(index == -1) cout << "Name not found!! " << endl;
//     else {
//         for(int i = index; i < size; i++) {
//             names[i] = names[i+1];
//         }
//         size--;
//     }
    

//     cout << "After : ";
//     for(int i = 0; i < size; i++) {
//         cout << names[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }



#include<iostream>
using namespace std;

int binary_search(int arr[], int number, int low, int high) {
    
    while(low <= high) {
        int mid = (low+high)/2;
        // cout << str[mid] << " ";
        if(arr[mid] == number) return mid;
        else if(arr[mid] > number) high = mid-1;
        else if(arr[mid] < number) low = mid+1;
    }
    return -1;
}

int main() {
    
    // Delete karim from a sorted array

    int nums[10] = {25, 28, 47, 58, 68, 79, 99, 100, 104};
    int size = 0;
    for(int i = 0; nums[i] != 0; i++) size++;
    cout << "Size Before Deleting : " << size << endl;
    int index = binary_search(nums, 25, 0, size-1);

    cout << "Before : ";
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;


    if(index == -1) cout << "Name not found!! " << endl;
    else {
        for(int i = index; i < size; i++) {
            nums[i] = nums[i+1];
        }
        size--;
    }
    

    cout << "After : ";
    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Size after deleting : " << size << endl;
    return 0;
}
