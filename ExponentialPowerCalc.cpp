#include <iostream>
#include <vector>
using namespace std;

// Effectively Calculates base^exp in O(logn) instead of O(n)
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    
    return 0;
}