// 1456 Maximun Number of Vowels in a Substring of Given Length
// Sliding Window

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>

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

int main(){
    string s = "abciiidef";
    int k = 3;
    int answer = MaxNumVowSubStr(s, k);
    cout << "maximum number of vowel letters in any substring of s with length k is : " << answer << endl;
    return 0; 
}