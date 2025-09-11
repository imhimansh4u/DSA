#include<iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int sum = 0;
            while(num>0){
                int digit = num%10;
                sum+=digit;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};
int main(){
    Solution s;
    cout<<"The answer is:: "<<s.addDigits(38);
    return 0;
}