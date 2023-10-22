// 1456 Maximun Number of Vowels in a Substring of Given Length
// Sliding Window

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int MaxNumVowSubStr(string s, int k){
    int sumVows = 0;
    int start = 0;
    int currLength = 0;
    int maxLength = 0;
    map<unsigned char, bool> charMap;
    charMap['a'] = true;
    charMap['e'] = true;
    charMap['i'] = true;
    charMap['o'] = true;
    charMap['u'] = true;


    for(int end=0; end<s.length();end++){
        currLength = end-start+1;

        if (charMap[s[end]]){
            sumVows++;
        }

        while(currLength >= k){
            maxLength = max(maxLength, sumVows);
            if (charMap[s[start]]){
                sumVows--;
            }
            start++;
            currLength=end-start-1;
        }
        
    }
    return maxLength;
}

int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};

int MaxNumVowSubStr_efficient(string s, int k){
    int max_vow = 0;
    // i = window's end
    // cur_vow = the count of vowels in the current window
    // max_vow = the maximum number of vowels seen so far
    for (auto i = 0, cur_vow = 0; i < s.size(); ++i) {
        cur_vow += vowels[s[i] - 'a']; // way of checking if a given character is a vowel and then updating the count of vowels
        // vowels[s[i] - 'a'] -> vowels[12 - 0] -> 0
        // vowels[s[i] - 'a'] -> vowels[4 - 0] -> 1
        // ... 
        if (i >= k)
            cur_vow -= vowels[s[i - k] - 'a']; // only subtracts if it's a vowel
        max_vow = max(max_vow, cur_vow);
    }
    return max_vow;
}


int main(){
    string s = "abciiidef";
    int k = 3;
    int answer = MaxNumVowSubStr_efficient(s, k);
    cout << "maximum number of vowel letters in any substring of s with length k is: " << answer << endl;
    return 0; 
}