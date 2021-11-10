#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int left, right, max;
        int now, run;
        string ans = "";
        
        
        now = -1;
        max = -1;
        left = right = 0;
        for (int i = 0; i < 2*length-1; i++) {
            if (i % 2 == 0) {
                now += 1;
                run = 1;
                while (now-run >= 0 && now + run < length) {
                    if (s[now-run] == s[now+run]) {
                        if (2*run+1 > max) {
                            max = 2*run + 1;
                            left = now-run;
                            right = now+run;
                        }
                        run += 1;
                    } else {
                        break;
                    }
                }
            } else {
                run = 0;
                while (now-run >= 0 && now+run+1 < length) {
                    if (s[now-run] == s[now+run+1]) {
                        if (2*run+2 > max) {
                            max = 2*run+2;
                            left = now-run;
                            right = now+run+1;
                        }
                        run += 1;
                    } else {
                        break;
                    }
                }
            }
        }
        for (int i = left; i <= right; i++) {
            ans += s[i];
        }
        return ans;
    }
};