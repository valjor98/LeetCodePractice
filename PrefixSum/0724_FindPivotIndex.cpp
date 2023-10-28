// 724. Find Pivot Index
// Hash map

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    
    int right = 0;
    vector<int> rightSums(n, 0);
    for(int i = n - 1; i >= 0; --i){
        rightSums[i] = right;
        right += nums[i];
    }

    int left = 0;
    vector<int> leftSums(n, 0);
    for(int i=0; i<n ; i++){
        leftSums[i] = left;
        left += nums[i];

        if(leftSums[i] == rightSums[i]){
            return i; 
        }
    }

    return -1;

}