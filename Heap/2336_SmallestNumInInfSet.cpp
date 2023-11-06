#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int cur;
set<int> s;

int SmallestInfiniteSet() {
    cur=1;
    return 0;
}

int popSmallest() {
    if(s.size()){
        int res=*s.begin(); s.erase(res);
        return res;
    }else{
        cur++;
        return cur-1;
    }
}

void addBack(int num) {
    if(cur>num) s.insert(num);
}
