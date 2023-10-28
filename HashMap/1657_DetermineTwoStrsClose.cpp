// 1657. Determine if Two Strings Are Close
// hash map

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
        return false;
    }

    unordered_map<char, int> count1, count2;
    set<char> set1, set2;

    for (char c : word1) {
        count1[c]++;
        set1.insert(c);
    }
    for (char c : word2) {
        count2[c]++;
        set2.insert(c);
    }

    // Check if both strings have the same set of characters
    if (set1 != set2) {
        return false;
    }

    // Check if both strings have the same set of frequencies
    multiset<int> freq1, freq2;
    for (auto& p : count1) freq1.insert(p.second);
    for (auto& p : count2) freq2.insert(p.second);

    return freq1 == freq2;       
}