#include <iostream>
using namespace std;

void findPairWithSum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
                return;
            }
        }
    }
    cout << "No pair found with the given sum." << endl;
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPairWithSum(arr, n, target);

    return 0;
}
