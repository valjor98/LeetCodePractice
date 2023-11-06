// 215. Kth Largest Element in an Array
//heap

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> queue; 
    int answer = 0;  
    for(int i=0; i<nums.size(); i++){
        queue.push(nums[i]);
    }
    for(int i=0; i<k-1; i++){
        queue.pop();
    }
    answer = queue.top();
    return answer;
}