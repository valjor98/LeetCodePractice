// 392. Is Subsequence
// Two Pointers

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;


bool isSubsequence(string s, string t) {
    int pt = 0;
    int ps = 0;
    if(s == ""){
        return true;
    }

    while(pt < t.length()){        
        if(t[pt] == s[ps]){
            ps++;
            if(ps == s.length()){
                return true;
            }
        }
        pt++;
    }
    return false;       
}

int main(){
    string s = "abc";
    string t = "ahbgdc";
    bool ans = isSubsequence(s, t);
    cout << ans << endl;
    return 0;
}