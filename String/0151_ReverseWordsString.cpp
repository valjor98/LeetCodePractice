// 0151 reverse words of a string
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

string reverseWords(string s){
        vector<string> store;        
        int start = 0;
        for (int end = 0; end <= s.length(); ++end) {
            if (end == s.length() || s[end] == ' ') {
                if (start != end) { 
                    string aux = s.substr(start, end - start);
                    store.push_back(aux);
                }
                start = end + 1;  
            }
        }
        
        string aux;
        for (int i = store.size() - 1; i >= 0; --i) {
            aux += store[i];
            if (i != 0) {
                aux += " ";
            }
        }
        return aux;
}

int main(){
    string s = "the sky is blue";
    string answer = reverseWords(s);
    cout << "answer: " << answer << endl;
    return 0;
}