// 283. Move Zeroes

// Two Pointers

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;


void moveZeroes(vector<int> nums){
    int write = 0; 

    for(int read = 0; read < nums.size(); ++read) {
        if(nums[read] != 0) {
            swap(nums[write], nums[read]);
            ++write; 
        }
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    cout << "Answer: " << nums[0] << endl;
    return 0; 
}