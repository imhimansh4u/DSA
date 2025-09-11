#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int main()
{
    int n;
    int m;
    cout << "Enter the value of m:: ";
    cin >> m;
    cout << "Enter the value of n:: ";
    cin >> n;
    int ans = gcd(m, n);
    cout << ans;
    return 0;
}
// complete and understand it properly
