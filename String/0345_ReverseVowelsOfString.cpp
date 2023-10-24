// 0345 reverse vowels of a string
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



string reverseVowels(string s) {
        map<unsigned char, bool> charMap;
        charMap['a'] = true;
        charMap['e'] = true;
        charMap['i'] = true;
        charMap['o'] = true;
        charMap['u'] = true;
        charMap['A'] = true;
        charMap['E'] = true;
        charMap['I'] = true;
        charMap['O'] = true;
        charMap['U'] = true;
        string aux;
        for(int i=0; i< s.length();i++){
            if(charMap[s[i]]){
                aux += s[i];
            }
        }
        for(int j=0; j< s.length();j++){
            if(charMap[s[j]]){
                s[j] = aux.back();
                aux.pop_back();
            }
        }
        return s;


}

string optimalReverseVowels(string s){
    string word = s;
    int start = 0;
    int end = s.length() - 1;
    string vowels = "aeiouAEIOU";
    
    while (start < end) {
        while (start < end && vowels.find(word[start]) == string::npos) {
            start++;
        }
        
        while (start < end && vowels.find(word[end]) == string::npos) {
            end--;
        }
        
        swap(word[start], word[end]);
        start++;
        end--;
    }
    return word;
}

int main(){
    string s = "leetcode";
    string answer = reverseVowels(s);
    //bool answer = PlaceFlowers(flowerbed, n);
    cout << "answer: " << answer << endl;
    return 0;
}