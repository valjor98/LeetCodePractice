// 0167 Two Sum II
// Two Pointers

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> TwoSumII(vector<int>& nums, int target){
    int leftP = 0;
    int rightP = nums.size()-1;
    while (leftP < rightP){
        int sum = nums[leftP] + nums[rightP];
        if (sum==target){
            int num1 = leftP+1;
            int num2 = rightP+1;
            return {num1, num2};
        }
        else if(sum < target){
            leftP++;
        }
        else{
            rightP--;
        }
    }
    return {}; 
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> answer = TwoSumII(nums, target);
    cout << "Answer: " << "[" << answer[0] << ", " << answer[1] << "]" << endl;
    return 0; 
}