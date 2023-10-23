// 1769 merge two strings
// Two Pointers

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

string mergeStings(string s1, string s2){
        int p1 = 0;
        int p2 = 0;
        string result = "";

        while(p1 < s1.length() || p2 < s2.length()){
            if(p1 < s1.length()){
                result += s1[p1];
                p1++;
            }
            if(p2 < s2.length()){
                result += s2[p2];
                p2++;
            }
        }
        return result;
}

int main(){
    string word1 = "abc";
    string word2 = "pqr";
    string answer = mergeStings(word1, word2);
    cout << answer << endl;
    return 0; 
}