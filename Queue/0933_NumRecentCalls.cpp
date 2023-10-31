// 933 Number of Recent Calls
// stacks

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

    queue<int> q;

int RecentCounter() {
    
    return 0;
}

int ping(int t) {
    q.push(t);

    while(q.front() < t-3000){
        q.pop();
    }

    return q.size();
}