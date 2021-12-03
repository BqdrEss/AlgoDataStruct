#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}f, 0

int findMax(int arr[], int n) {
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    const int m = findMax(arr, n) + 1;
    int C[m];
    for (int i = 0; i < m; i++) {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
        C[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        C[i] += C[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[C[(arr[i] / exp) % 10] - 1] = arr[i];
        C[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSotr(int arr[], int n) {
    int m = findMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Unsorted version of the array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Sorted version of the array: " << endl;
    radixSotr(arr, n);
    print(arr, n);

    return 0;
}