#include <iostream>
using namespace std;

int modPower(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

bool isProbablyPrime(int n, int a) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    return modPower(a, n - 1, n) == 1;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int bases[] = {2, 3, 5};
    bool isPrime = true;

    for (int i = 0; i < 3; i++) {
        if (!isProbablyPrime(num, bases[i])) {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
        cout << "prime\n";
    else
        cout << "Composite\n";

    return 0;
}
