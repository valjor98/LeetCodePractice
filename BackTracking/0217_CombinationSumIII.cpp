// 216. Combination Sum III
// DST, Recursivity, backtracking

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>


using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> output;
    vector<int> results;
    int sum = 0;
    int lastDigit = 1;
    DFS(k, n, sum, lastDigit, results, output);
    return output;
}

void DFS(int k, int n, int sum, int start, vector<int>& results, vector<vector<int>>& output) {
    if(k==0 && n==sum){
        output.push_back(results);
        return;
    }
    if (sum > n) {
        return;
    }
    for(int i=start; i < 10; i++){
        results.push_back(i);
        DFS(k - 1, n, sum + i, i + 1, results, output);
        results.pop_back(); // backtracking
    }
}