// 1431 Kids With the Greatest Number of Candies
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


vector<bool> kidcandies(vector<int> candies, int extraCandies){
    int maxV = 0;
    vector<bool> res;

    for(int i=0; i<candies.size(); i++){
        if(candies[i] >= maxV){
            maxV = candies[i];
        }
    }
    cout << "max:" << maxV << endl;

    for(int i=0; i<candies.size(); i++){
        int sum = candies[i] + extraCandies;
        cout << "sum: " << sum << endl;
        if(sum >= maxV){
            res.push_back(true);
        }
        else{
            res.push_back(false);
        }
    }
    return res; 
}


int main(){
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    vector<bool> result =  kidcandies(candies, extraCandies);
    for(int i=0; i < result.size(); i++){
        cout << result[i] << ", ";
    }
    return 0;
}