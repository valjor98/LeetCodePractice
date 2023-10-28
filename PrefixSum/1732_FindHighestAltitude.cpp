// 1732. Find the Highest Altitude
// Hash map

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

int largestAltitude(vector<int>& gain) {
    int maxV = 0;
    int sum = 0;
    for(int i=0; i<gain.size(); i++){
        sum += gain[i];
        maxV = max(maxV, sum);
    }
    return maxV; 
}