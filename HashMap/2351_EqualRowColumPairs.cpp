// 1657. Determine if Two Strings Are Close
// hash map

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    unordered_map<string, int> columns;
    unordered_map<string, int> rows;
    int n = grid[0].size();
    for(int i=0; i<n ; i++ ){
        string auxC, auxR;
        for(int j=0; j<n ; j++){
            auxC += to_string(grid[i][j]) + ",";
            auxR += to_string(grid[j][i]) + ",";
        }
        columns[auxC]++;
        rows[auxR]++;
    }

    int counter = 0;
    for(auto& c : columns){
        if(rows[c.first]){
            counter = (counter + rows[c.first])*c.second;
        }
    }

    return counter;
        
}