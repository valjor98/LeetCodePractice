// 238. Product of Array Except Self
// arrays, strings

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);  // Initialize result array with 1s
    
    // Calculate the product of all elements to the left of each index
    int left_product = 1;
    for (int i = 0; i < n; i++) {
        result[i] *= left_product;
        left_product *= nums[i];
    }
    
    // Calculate the product of all elements to the right of each index
    int right_product = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= right_product;
        right_product *= nums[i];
    }
    
    return result;
}


int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> answer = productExceptSelf(nums);
    for(int i=0; i<nums.size(); i++){
        cout << answer[i] << ", ";
    }
    
}