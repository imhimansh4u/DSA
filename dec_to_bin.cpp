#include <iostream>
#include <math.h>
// #include <cmath>
using namespace std;
int main()
{
    //  program to find the bit representation of any number .
    int n;
    cout << "Enter the value of n  :: " << endl;
    cin >> n;
    int ans = 0;
    int ispowerof10 = 1;
    if (n >= 0)
    {
        while (n != 0)
        {
            /*cout<<(n & 1);          if we directly print the number like this it will print in the reverse order  ..*/
            int digit = (n & 1);                   // variable to store the bits .
            /*ans = (digit * pow(10, i)) + ans; */ // we will not use pow() function here because it can may give precision issue ...
            ans += (digit * ispowerof10);
            n = n >> 1;
            ispowerof10 *= 10;
        }
    }
    // conversion of negative numbers into binary (still in progress i.e. not complete code)
    // else
    // {
    //     int nn = (-1)*n;
    //     while (nn != 0)
    //     {
    //         int digit = (nn ^ 1);
    //         ans += (digit * ispowerof10);
    //         nn = nn >> 1;
    //         ispowerof10 *= 10;
    //     }
    // }
    cout << ans<<endl;
    // code to convert any binary number to decimal
    int bin_num;
    cout<<"Enter binary representation of any number :: ";
    cin>>bin_num;
    int decimal_representation = 0;
    int powerof2 = 1;
    while(bin_num!=0){
        int dig = bin_num%10;
        decimal_representation += (dig*powerof2);
        powerof2 *= 2;
        bin_num /= 10;
    }
    cout<<decimal_representation;
    return 0;
}