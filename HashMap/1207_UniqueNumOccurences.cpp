// 1207. Unique Number of Occurrences
// hash map

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> occurences;
    map<int, bool> same;

    for(int i=0; i<arr.size(); i++){
        occurences[arr[i]]++;
    }
    for(const auto& pair : occurences){
        if(same[pair.second] == true){
            return false;
        }
        else{
            same[pair.second] = true;
        }
    }
    return true;
}