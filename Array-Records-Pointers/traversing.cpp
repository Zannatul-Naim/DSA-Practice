#include<iostream>
#include<math.h>
using namespace std;

int main() {
    double a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    double max_val = -1000000;
    double min_val = 1000000;

    double total_val = 0;
    double avg_val = 0;

    double sin_val;
    double cos_val;

    int size = sizeof(a) / sizeof(double);
    cout << "Size of the array : " << size << endl;

    for(int i = 0; i < size; i++) {
        if(a[i] > max_val) max_val = a[i];
        if(a[i] < min_val) min_val = a[i];

        total_val += a[i];

        cout << "sin value of " << a[i] << " is : " << sin(a[i]) << endl;
        cout << "cos value of " << a[i] << " is : " << cos(a[i]) << endl;
    }

    cout << endl;

    cout << "Total value : " << total_val << endl;

    avg_val = (total_val / size);

    cout << "Average value : " << avg_val << endl;

    return 0;

}