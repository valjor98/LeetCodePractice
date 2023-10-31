// 649. Dota2 Senate
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

string predictPartyVictory(string senate) {
    queue<int> R;
    queue<int> D;

    for(int i=0; i<senate.length(); i++){
        if(senate[i] == 'R'){
            R.push(i);
        }
        else{
            D.push(i);
        }
    }

    while(!R.empty() && !D.empty()){
        int auxR = R.front();
        int auxD = D.front();
        R.pop();
        D.pop();
        if(auxR < auxD){
            R.push(auxR+senate.size());
        }
        else{
            D.push(auxD+senate.size());
        }
    }
    cout << R.size() << ", " << D.size() << endl;
    if(R.size() > D.size()){
        return "Radiant";
    }
    else{
        return "Dire";
    }
}