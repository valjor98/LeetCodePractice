// 704 Binary Search
// BS

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size()-1;

    while(start <= end){
        int mid = (end+start) / 2 ;
        
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] > target){
            end = mid - 1;
        }
        if(nums[mid] < target){
            start = mid + 1;
        }
    }

    return -1;
}