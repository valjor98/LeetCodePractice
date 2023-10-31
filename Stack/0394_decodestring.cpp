// 394. Decode String
// stacks

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

string decodeString(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ']') {
            st.push(s[i]);
            cout << s[i];
        }
        else{
            string curr_str = "";
            
            while(st.top() != '['){
                curr_str = st.top() + curr_str ;
                st.pop();
            }
            cout << endl;
            cout << "curr_str: " << curr_str <<  endl;
            
            st.pop();   // for '['
            string number = "";
            
            // for calculating number
            
            while(!st.empty() && isdigit(st.top())){
                number = st.top() + number;
                st.pop();
            }
            cout << "number: " << number <<  endl;
            int k_time = stoi(number);    // convert string to number
            
            while(k_time--){
                cout << "k_time: " << k_time <<  endl;
                for(int p = 0; p < curr_str.size() ; p++)
                    st.push(curr_str[p]);
            }
        }
    }
    
    s = "";
    while(!st.empty()){
        s = st.top() + s;
        st.pop();
    }
    return s;

}