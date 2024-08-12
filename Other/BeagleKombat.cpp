#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> damage(n);
    for (int i = 0; i < n; ++i) {
        cin >> damage[i];
    }

    string sequence;
    cin >> sequence;

    long long maxDamage = 0;
    int i = 0;

    while (i < n) {
        char currentChar = sequence[i];
        vector<int> currentDamages;

        while (i < n && sequence[i] == currentChar) {
            currentDamages.push_back(damage[i]);
            i++;
        }

        sort(currentDamages.rbegin(), currentDamages.rend());
        for (int j = 0; j < min(k, (int)currentDamages.size()); ++j) {
            maxDamage += currentDamages[j];
        }
    }

    cout << maxDamage << endl;

    return 0;
}
