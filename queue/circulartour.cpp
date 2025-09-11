/*There are some gas stations along a circular route, where the amount of gas at the station is gas[i]. You have a car with an unlimited gas tank
 and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the 
 gas stations. Given two integer arrays gas as a1and cost as a2, return the starting gas station's index if you can travel around the circuit once
in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.
*/
#include<iostream>
#include<queue>
using namespace std;
// APPROACH 1)) BRUTE FORCE APPROACH -> T.C. -- >> O(n).. (in worst case)
class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        // Your code here
        int n = a1.size();
        for(int start=0;start<n;start++){       // try starting from each gas station....
            bool cantravel = true;
            int tankcapacity  = 0;
            for(int i = 0;i<n;i++){           // check if the car can complete the circuit
                int currentstation = (start+i)%n;  // helps to tavel in circular
                tankcapacity += a1[currentstation] - a2[currentstation];  // we have assumed that 1 unit of gas costs , one unit of cost
                // check if can travel to nest gas station or not
                if(tankcapacity < 0){    // it means cost of gas is more than the gas available .. therefore cannot travel...
                    cantravel = false;
                    break;
                }
            }
            if(cantravel){
                return start;
            }
        }
        return -1;
    }
};
// optimal approach -2)) using the concept that if (totalgas available >= totalcost) then there must exist any solution..
class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        // Your code here
        int n = a1.size();
        int start = 0; // The starting station
        int tank = 0;  // Current fuel in the tank
        int totalGas = 0, totalCost = 0; // Track total gas and cost for feasibility check
    
        for (int i = 0; i < n; ++i) {
            totalGas += a1[i];
            totalCost += a2[i];
            tank += a1[i] - a2[i];
    
            if (tank < 0) {
            // Reset starting point and tank
                start = i + 1;
                tank = 0;
            }
        }
    
        // If total gas is less than total cost, completing the circuit is impossible
        return (totalGas >= totalCost) ? start : -1;
    }
};

int main(){

    return 0;
}