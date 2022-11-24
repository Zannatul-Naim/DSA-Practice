#include<iostream>
using namespace std;



void printnums(int arr[], int size) {
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void printnames(string str[], int size) {
    for(int i = 0; i < size; i++) cout << str[i] << " ";
    cout << endl;
}

void bubble_sort_nums(int a[], int size) {
    // int cnt = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void bubble_sort_names(string s[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(s[j].compare(s[j+1]) > 0) {
                string temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main() {
    int nums[10] = {12, 14, 28, 3, 4, 25, 98, 15, 20, 10};
    string names[10] = {"karim", "naim", "ashraful", "shakil", "sayeed", "ashik", "afif", "habib", "shab", "aaa"};
    cout << "Before Sorting : " << endl;
    printnums(nums, 10);
    printnames(names, 10);

    bubble_sort_nums(nums, 10);
    bubble_sort_names(names, 10);

    cout << "After Sorting : " << endl;
    printnums(nums, 10);
    printnames(names, 10);

    return 0;
}