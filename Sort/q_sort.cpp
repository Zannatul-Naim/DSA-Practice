#include<iostream>
using namespace std;


int partition(int a[], int low, int high, int pivot) {
    int i, j;
    i = j = low;

    while(i <= high) {
        if(a[i] > pivot) i++;
        else {
            swap(a[i], a[j]);
            i++;
            j++;
        }
    }
    return j-1; 

}

void quick_sort(int a[], int low, int high) {

    if(low < high) {
        int pivot = a[high];
        int pos = partition(a, low, high, pivot);

        quick_sort(a, low, pos-1);
        quick_sort(a, pos+1, high);
    }
}

int main() {

    int a[10] = {5,6,8,44,12,98,75,14,23,56};
    quick_sort(a, 0, 9);

    for(int i = 0; i < 10; i++) cout << a[i] << " ";
    cout << endl;

    return 0;

}