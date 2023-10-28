// 2215. Find the Difference of Two Arrays
// hashmaps

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

vector<vector<int>> findDifference1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vect1;
    vector<int> vect2;
    map<int, bool> present1;
    map<int, bool> present2;

    for(int i=0; i<nums1.size();i++){
        present1[nums1[i]] = true;
    }
    for(int i=0; i<nums2.size();i++){
        present2[nums2[i]] = true;
        if(!present1[nums2[i]]){
            present1[nums2[i]] = true;
            vect2.push_back(nums2[i]);
        }
    }
    for(int i=0; i<nums1.size();i++){
        if(!present2[nums1[i]]){
            present2[nums1[i]] = true;
            vect1.push_back(nums1[i]);
        }
    }
}

vector<vector<int>> findDifference2(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    
    vector<int> distinct_nums1, distinct_nums2;
    for (int num : set1) {
        if (set2.count(num) == 0) {
            distinct_nums1.push_back(num);
        }
    }

    for (int num : set2) {
        if (set1.count(num) == 0) {
            distinct_nums2.push_back(num);
        }
    }

    return {distinct_nums1, distinct_nums2};
}



