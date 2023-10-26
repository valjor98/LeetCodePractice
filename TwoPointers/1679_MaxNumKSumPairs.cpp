// 392. Is Subsequence
// Two Pointers, hash table

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;


int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        if(m[k - nums[i]] > 0){
            m[k - nums[i]]--;
            ans++;
        }
        else{
            m[nums[i]]++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4};
    int k = 6;
    int ans = maxOperations(nums, k);
    return 0;
}