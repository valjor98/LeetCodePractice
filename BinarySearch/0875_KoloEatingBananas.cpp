// 875. Koko Eating Bananas
// BS

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

long long check(vector<int>& piles, long long k) {
    long long sum = 0;
    for(auto&& pile : piles) {
        long long s = ceil((double)pile / k);
        sum += s;
    }
    return sum;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int maxV = 0;
    for(auto&& pile : piles){
        maxV = max(maxV, pile);
    }
    
    int start = 1; // Changed from 0 to 1
    int end = maxV;
    long long minK = INT_MAX; // Initialize to a large value

    while(start <= end) {
        long long mid = start + (end - start) / 2;
        long long ans = check(piles, mid);
        
        if(ans > h) {
            start = mid + 1;
        } else {
            end = mid - 1;
            minK = min(minK, mid);
        }
    }

    return minK;
}