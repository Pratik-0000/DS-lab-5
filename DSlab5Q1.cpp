#include <iostream>
using namespace std;
const int MAX_PERM = 100;
int results[MAX_PERM][3]; 
int permIndex = 0;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; ++i)
            results[permIndex][i] = arr[i];
        permIndex++;
        return;
    }
    for (int i = start; i <= end; ++i) {
        swap(arr[start], arr[i]);
        generatePermutations(arr, start + 1, end);
        swap(arr[start], arr[i]);
    }
}
bool isGreater(int a[], int b[], int size) {
    for (int i = 0; i < size; ++i) {
        if (a[i] < b[i]) return false;
        if (a[i] > b[i]) return true;
    }
    return false;
}
void sortPermutations(int size) {
    for (int i = 0; i < permIndex - 1; ++i) {
        for (int j = i + 1; j < permIndex; ++j) {
            if (isGreater(results[i], results[j], size)) {
                for (int k = 0; k < size; ++k)
                    swap(results[i][k], results[j][k]);
            }
        }
    }
}
int main() {
    int arr[] = {7, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    generatePermutations(arr, 0, n - 1);
    sortPermutations(n);

    cout << "Sorted permutations:\n";
    for (int i = 0; i < permIndex; ++i) {
        for (int j = 0; j < n; ++j)
            cout << results[i][j] << " ";
        cout << endl;
    }

    return 0;
}
