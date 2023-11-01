// 374. Guess Number Higher or Lower
// BS

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

int guess(int mid){
    return 1;
}

int guessNumber(int n) {
    int start = 0;
    int end = n; 

    while( start <= end ){
        double mid = start + (end - start) / 2.0;
        int target = guess(mid);

        if(target == 0 ){
            return mid;
        }
        if(target == 1){
            start = mid+1; 
        }
        if(target == -1){
            end = mid-1;
        }
    }

    return -1;
}