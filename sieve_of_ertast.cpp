#include<iostream>
#include<vector>
#include<algorithm>
               /*Finding total number of prime numbers using the alg. of sieve of eratosthenes*/

using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> isprime(n+1,1);     // marking all the number upto n as prime numbers 
        isprime[0] = isprime[1] = 0;     // marking 0 and 1 as non prime numbers
        for(int i = 2;i<n;i++){          
            if(isprime[i]){             // if number is prime increament count by 1
                count++;
                for(int j = 2*i;j<n;j = j+i){        /*  marking all the numbers as non prime which comes
                                                       in table of prime number (i) upto n     */
                    isprime[j] = 0;
                }
            }
        }
        return count;
    }
};

int main(){
    int n;
    cout<<"Enter the element upto which you wants to count the prime number"<<endl;
    cin>>n;
    Solution s;
    cout<<"The total number of primes present upto "<<n <<" is:: "<<endl;
    int total =  s.countPrimes(n);
    cout<<total;
    return 0;
}


   /* time complexity of SOE is --->> O[n*log(log(n))]      
      where n is the num. upto which we have to find the total primes*/