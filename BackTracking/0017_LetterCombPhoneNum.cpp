// 17. Letter Combinations of a Phone Number
// DST, Recursivity, bakctracking

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

unordered_map<char, string> my_map = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};



vector<string> letterCombinations(string digits) {
    if(digits.empty()){
        return {};
    }
    vector<string> result; 
    string aux;
    int index = 0; 
    DFS(digits, result, aux, index);
    return result; 
}

void DFS(string digits, vector<string>& result, string& aux, int index){
    if(index == digits.length()){
        result.push_back(aux);
        return;
    }
    string value = my_map[digits[index]];
    for(int i=0; i<value.size(); i++){
        aux.push_back(value[i]);
        DFS(digits, result, aux, index+1);
        aux.pop_back();
    }
}