// 209 Minimum Size SubArray Sum
// Sliding window

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int minSubArraySum(vector<int> nums, int target){
    int longestSum = 0;
    int minLength = INT_MAX;
    int start = 0;

    for(int end=0;end<nums.size();end++){
        longestSum += nums[end];
        while (longestSum >= target) {
            int windowSize = end - start + 1;
            minLength = min(minLength, windowSize);
            longestSum -= nums[start];
            start++;
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}


int main(){
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    double answer = minSubArraySum(nums, target);
    cout << "The minimum sum is: " << answer << endl;
    return 0;
}