// 0021 Merge Two Sorted Linked List
// Two Pointers

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int MaxConOnes(vector<int> nums, int k){
    int start = 0; 
    int MaxOnes = 0;
    map<int, bool> mymap;

    for(int end=0; end<nums.size(); end++){
        if(!(nums[end])){
            mymap[end] = true;
        }
        
        while(mymap.size() > k){
            if(!(nums[start])){
                mymap.erase(start);
            }
            start++;
        }
        int currLength = end - start + 1;
        MaxOnes = max(currLength, MaxOnes);
    }
    return MaxOnes; 
}

// nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

int main(){
    int k = 2;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int answer = MaxConOnes(nums, k);
    cout << "Answer: " << answer << endl;
    return 0; 
}