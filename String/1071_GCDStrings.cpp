// 1071 Greatest Common Divisor for two Strings
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


string GCDString(string str1, string str2){
        if(str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0, __gcd(str1.size(), str2.size()));  
}


int main(){
    string str1 = "ABCABC";
    string str2 = "ABC";
    string answer = GCDString(str1, str2);
    cout << "answer:" << answer << endl;
    return 0;
}