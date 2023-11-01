// 2300. Successful Pairs of Spells and Potions
// BS

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> result;
    sort(potions.begin(), potions.end());

    for(int spell : spells) {
        int low = 0, high = potions.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long product = (long long) spell * potions[mid];

            if(product >= success) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(ans == -1) {
            result.push_back(0);
        } else {
            result.push_back(potions.size() - ans);
        }
    }

    return result;
}