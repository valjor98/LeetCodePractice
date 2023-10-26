// 1493 Longest Subarray of 1s after deleting one element
// Sliding window

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();

    int left = 0;
    int zeros = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        if (nums[right] == 0) {
            zeros++;
        }
        while (zeros > 1) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }
        ans = max(ans, right - left + 1 - zeros);
    }
    return (ans == n) ? ans - 1 : ans;
}