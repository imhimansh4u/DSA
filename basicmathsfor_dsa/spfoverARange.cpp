// Find Prime Factors of a range using concept of spf(smallest Prime Factors)

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int range = 100000 + 1; //  bcs maximum que asked for 10^5 Range
    // find sieve of ersastothenes(spf -> Smallest Prime Factors)
    vector<int> sieve(range);
    for (int i = 0; i < range; i++)
    {
        sieve[i] = i;
    }
    for (int i = 2; i * i <= range; i++)
    {
        if (sieve[i] == i)
        { // It means Prime
            for (int j = i * i; j < range; j += i)
            {
                if (sieve[j] == j)
                {
                    sieve[j] = i;
                }
            }
        }
    }
    int n;
    cout << "Enter Query size::-->" << endl;
    cin >> n;
    while (n > 1)
    {
        cout << sieve[n] << " ";
        n /= sieve[n];
    }

    return 0;
}