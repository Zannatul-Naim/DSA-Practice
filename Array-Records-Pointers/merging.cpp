// #include<iostream>
// using namespace std;

// void merge_sorted(int nums[], int nums1[] , int nums2[], int size1, int size2) {
//     int i = 0, j = 0, k = 0;

//     while(i < size1 && j < size2) {
//         if(nums1[i] < nums2[j]) {
//             nums[k] = nums1[i];
//             i++;
//             k++;
//         } 
//         else {
//             nums[k] = nums2[j];
//             j++;
//             k++;
//         }
//     }
//     while(i < size1) {
//         nums[k] = nums1[i];
//         k++;
//         i++;
//     }
//     while(j < size2) {
//         nums[k] = nums2[j];
//         k++;
//         j++;
//     }

// }

// void merge_unsorted(int nums[], int nums1[], int nums2[], int size1, int size2) {
    
//     int j = 0;
//     for(int i = 0; i < size1; i++) nums[j++] = nums1[i];
//     for(int i = 0; i < size2; i++) nums[j++] = nums2[i];

// }

// void printArray(int a[], int size) {
//     for(int i = 0; i < size; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
    
//     int nums1[5] = {1, 3, 5, 7, 9};
//     int nums2[5] = {2, 4, 6, 8, 10};

//     int nums_sorted[10];
//     int nums_unsorted[10];

//     merge_unsorted(nums_unsorted, nums1, nums2, 5, 5);
//     printArray(nums_unsorted, 10);

//     merge_sorted(nums_sorted, nums1, nums2, 5, 5);
//     printArray(nums_sorted, 10);

//     return 0;
// }


#include<iostream>

using namespace std;

void merge_unsorted(char ch[], char ch1[], char ch2[], int size1, int size2) {
    
    int k = 0;
    for(int i = 0; i < size1; i++) ch[k++] = ch1[i];
    for(int i = 0; i < size2; i++) ch[k++] = ch2[i];
}

void merge_sorted(char ch[], char ch1[], char ch2[], int size1, int size2) {

    int i = 0, j = 0, k = 0;

    while(i < size1 && j < size2) {
        if(ch1[i] < ch2[j]) {
            ch[k] = ch1[i];
            k++;
            i++;
        }
        else {
            ch[k] = ch2[j];
            k++;
            j++;
        }
    }

    while(i < size1) {
        ch[k] = ch1[i];
        k++;
        i++;
    }
    while(j < size2) {
        ch[k] = ch2[j];
        k++;
        j++;
    }
}

void printArray(char ch[], int size) {
    for(int i = 0; i < size; i++) {
        cout << ch[i] << " ";
    }
    cout << endl;
}

int main() {
    
    char ch1[5] = {'a', 'c', 'e', 'g', 'i'};
    char ch2[5] = {'b', 'd', 'f', 'h', 'j'};
    char ch_sorted[10];
    char ch_unsorted[10];

    merge_unsorted(ch_unsorted, ch1, ch2, 5, 5);
    printArray(ch_unsorted, 10);

    merge_sorted(ch_sorted, ch1, ch2, 5, 5);
    printArray(ch_sorted, 10);

    return 0;

}