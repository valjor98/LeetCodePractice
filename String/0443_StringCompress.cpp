// 443 string compression
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

int compress(vector<char>& chars) {
    int write = 0; // Pointer to write compressed characters and counts
    int read = 0;  // Pointer to read original characters

    while (read < chars.size()) {
        char currentChar = chars[read]; // Current character being compressed
        int count = 0;  // Count of consecutive occurrences of currentChar

        // Count consecutive repeating characters
        while (read < chars.size() && chars[read] == currentChar) {
            read++;
            count++;
        }

        // Write the character to the compressed array
        chars[write++] = currentChar;

        // If the count is greater than 1, write it to the compressed array
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[write++] = c;
            }
        }
    }
}

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int answer = compress(chars);
    cout << answer << endl;
    return 0;
}