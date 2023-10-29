// 2390. Removing Stars From a String
// stacks

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

string removeStars(string s) {
    string answer;
    for(int i=0; i< s.length(); i++){
        if((s[i]-'a') >= 0 && (s[i]-'a') < 26){
            answer.push_back(s[i]);
        }
        else if(s[i] == '*'){
            answer.pop_back();
        }
    }
    return answer;
}