// 605 Can Place Flowers
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

bool PlaceFlowers(vector<int>& flowerbed, int n){
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;
}

int main(){
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 2;
    bool answer = PlaceFlowers(flowerbed, n);
    cout << "answer:" << answer << endl;
}