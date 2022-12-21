void rotate(int arr[], int n)
{
    int a[n];
    a[0] = arr[n-1];
    for(int i = 0; i < n-1; i++) {
        a[i+1] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = a[i];
    }
}


// Another Solution 

//     void rotate(int arr[], int n)
//     {
//         for(int i = n-1; i >= 1; i--) {
//             swap(arr[i],arr[i-1]);
//         }
//     }
