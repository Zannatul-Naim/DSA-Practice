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

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pivot = a[high];
        int pos = partition(a, low, high, pivot);

        quickSort(a, low, pos-1);
        quickSort(a, pos+1, high);
    }
}

void print(int a[], int size) {
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    
    // int a[] = {5,6,3,2,1,19,16,17,23,18};
    int a[] = {1,5,3,2};
    int size = sizeof(a) / sizeof(int);

    cout << "Before sort : ";
    print(a, size);
    quickSort(a, 0, size-1);
    cout << "After sort : ";
    print(a, size);
    // quickSort(a, 0, size-1);
    return 0;

}