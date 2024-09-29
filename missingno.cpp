#include <iostream>
using namespace std;

int missingno(int arr[], int size) {
    int start, end;
    cout << "Enter the starting number: "<<endl;
    cin >> start;
    cout << "Enter the ending number: ";
    cin >> end;

    if (start >= end) {
        cout << "Invalid range. Starting number should be less than ending number." << endl;
        return -1;
    }

    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < size; i++) {
        xor1 ^= arr[i];
    }
    for (int i = start; i <= end; i++) {
        xor2 ^= i;
    }
    return xor1 ^ xor2;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Size should be greater than 0." << endl;
        return -1;
    }

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int miss = missingno(arr, size);
    if (miss != -1) {
        cout << "Missing number is " << miss << endl;
    }

    delete[] arr;
    return 0;
}

  
