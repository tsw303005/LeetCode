#include <stack>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> temp;
        char c;
        int num = s.length();
        for (int i = 0; i < num; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                temp.push(s[i]);
            } else if (s[i] == ')') {
                if (temp.empty()) return false;
                c = temp.top();
                temp.pop();
                if (c != '(') {
                    return false;
                }
            } else if (s[i] == '}') {
                if (temp.empty()) return false;
                c = temp.top();
                temp.pop();
                if (c != '{') {
                    return false;
                }
            } else {
                if (temp.empty()) return false;
                c = temp.top();
                temp.pop();
                if (c != '[') {
                    return false;
                }
            }
        }
        if (temp.empty()) {
            return true;
        } else {
            return false;
        }
    }
};