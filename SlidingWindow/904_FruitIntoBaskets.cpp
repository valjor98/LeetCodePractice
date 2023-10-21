// 904. Fruit Into Baskets

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int fruitIntoBasket_3(vector<int> trees){
    map<int, bool> treeTypesMap;
    int maxValue = 0;
    int start = 0;

    for (int end=0; end < trees.size(); end++){
        int treeType = trees[end];
        if (treeTypesMap.size() > 2 && !(treeTypesMap[treeType])){
            int windowSize = end-start+1;
            maxValue = max(maxValue, windowSize);
        }
        else if (treeTypesMap[treeType]) {
            int windowSize = end-start+1;
            maxValue = max(maxValue, windowSize);       
        }
        else {
            map<int, bool> treeTypesMap;
            treeTypesMap[end-1] = true;
            treeTypesMap[treeType] = true;
            start = end - 1;
        }

        while(start > 0 && trees[start] == trees[start-1]){
            start--;
        } 
    }
    return maxValue;
}


int fruitIntoBasket(vector<int> fruits){
    map<int, int> treeTypesMap;
    int maxValue = 0;
    int start = 0;

    for (int end = 0; end < fruits.size(); end++) {
        int treeType = fruits[end];
        // Update frequency of the fruit in the current window
        treeTypesMap[treeType]++;
        
        // Check if we have more than two types of fruits in the current window
        while (treeTypesMap.size() > 2) {
            int startType = fruits[start];
            treeTypesMap[startType]--; // decrement because we're going to slide the window forward, effectively "removing" this fruit from the current window
            if (treeTypesMap[startType] == 0) {
                treeTypesMap.erase(startType);
            }
            start++;
        }
        
        // Update maximum
        int windowSize = end - start + 1;
        maxValue = max(maxValue, windowSize);
    }
    return maxValue;
}


int main() {
    int k = 4;
    vector<int> trees = {1, 2, 3, 2, 2};
    int answer = fruitIntoBasket(trees);
    cout << "The maximum average is: " << answer << endl;
    return 0;
}