// 643 Maximum Average Subarray I
// Dynamic sliding window

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// O(n)
float findMaxAverage_SW(vector<int>& nums, int k){
    double Average = -INFINITY; // Sets to negative infinity
    double count = 0;

    for (int i = 0; i < nums.size(); i++) {
        count += nums[i];
        if (i >= k) count -= nums[i - k];
        if (i+1 >= k) Average = max(count, Average);
    }
    return Average / double(k);
}

int main() {
    int k = 4;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    double answer = findMaxAverage_SW(nums, k);
    cout << "The maximum average is: " << answer << endl;
    
    return 0;
}