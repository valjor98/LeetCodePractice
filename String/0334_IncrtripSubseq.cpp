// 334. Increasing Triplet Subsequence
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

bool increasingTriplet(vector<int>& nums) {
    int n=nums.size();
    if(n<3)return false;       //if size of array is less than 3 we can't make triplate
    int low=INT_MAX, mid=INT_MAX;
    for(int i=0;i<n;i++){
        if(nums[i]>mid){
            return true;
        }
        else if(nums[i]<low){
            low=nums[i];
        }
        else if(nums[i]> low and nums[i]<mid){
            mid=nums[i];
        }
    }
    return false;
    }

int main(){
    vector<int> nums = {2,1,5,0,4,6};
    bool answer = increasingTriplet(nums);
    cout << answer << endl;
    
}