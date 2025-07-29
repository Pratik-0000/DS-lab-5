#include <iostream>
using namespace std;

void printCombination(int comb[], int r) {
    for (int i = 0; i < r; ++i)
        cout << comb[i] << " ";
    cout << endl;
}

bool nextCombination(int comb[], int n, int r) {
    int i = r - 1;
    while (i >= 0 && comb[i] == n - r + i + 1)
        i--;

    if (i < 0)
        return false; // No more combinations

    comb[i]++;
    for (int j = i + 1; j < r; ++j)
        comb[j] = comb[i] + j - i;

    return true;
}

int main() {
    int n, r;
    cout << "Enter the value of n (size of the set): ";
    cin >> n;
    cout << "Enter the value of r (size of combination): ";
    cin >> r;

    if (r > n || r < 1) {
        cout << "Invalid input: r must be between 1 and n.\n";
        return 1;
    }

    int comb[r];
    for (int i = 0; i < r; ++i)
        comb[i] = i + 1;

    cout << "Initial combination: ";
    printCombination(comb, r);

    if (nextCombination(comb, n, r)) {
        cout << "Next combination: ";
        printCombination(comb, r);
    } else {
        cout << "No next combination exists.\n";
    }

    return 0;
}
