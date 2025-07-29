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
bool isProbablyPrime(int n) {
    int a = 2;
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    if (modPower(a, n - 1, n) != 1)
        return false;
    return true;
}

int main() {
    int num;
    cout<<"Enter a number";
    cin >> num;
    if (isProbablyPrime(num))
        cout << "prime\n";
    else
        cout << "Composite\n";
    return 0;
}
