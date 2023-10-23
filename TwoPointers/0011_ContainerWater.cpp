// 0011 Container with the Most Water
// Two Pointers

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int containerWater(vector<int> heights){
    int leftP = 0;
    int rightP = heights.size()-1;
    int largestV = 0;
    while(leftP < rightP){
        int width = rightP - leftP;
        int height = min(heights[leftP], heights[rightP]);
        int volume = width*height;
        largestV = max(volume, largestV);
        if(heights[leftP] <= heights[rightP]){
            leftP++;
        } else{
            rightP--;
        }
    }
    return largestV;
}


int main(){
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    int answer = containerWater(heights);
    cout << "Answer: " << answer << endl;
    return 0; 
}