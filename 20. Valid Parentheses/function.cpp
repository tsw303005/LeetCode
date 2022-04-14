#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string st;
        
        for (auto i : s) {
            if (i == '(' or i == '{' or i == '[') {
                st += i;
            } else {
                if (i == ')' and st.back() == '(') st.pop_back();
                else if (i == ']' and st.back() == '[') st.pop_back();
                else if (i == '}' and st.back() == '{') st.pop_back();
                else return false;
            }
        }
        
        return st.length() == 0;
    }
};