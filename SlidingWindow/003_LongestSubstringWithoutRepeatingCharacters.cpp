// 3 Longest Substring Without Repeating Characters
// Sliding window

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int longestSubstringWithoutRepeat(string s){
    map<unsigned char, bool> charMap;
    int largestSubLen = 0;
    int start = 0;

    for (int end=0; end < s.length(); end++){
        char character = s[end];
        if (!charMap[character]){
            charMap[character] = true;
            int windowSize = end-start+1;
            largestSubLen = max(largestSubLen, windowSize);
        }
        else{
            while( charMap[character] ){
                charMap[s[start]] = false;
                start++;  
            } 
            charMap[character] = true;
        }
    }
    return int(largestSubLen);

}


int main() {
    string s = "pwwkew";
    int answer = longestSubstringWithoutRepeat(s);
    cout << "The maximum average is: " << answer << endl;
    
    return 0;
}