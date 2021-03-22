#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lower = lower_bound(arr.begin(), arr.end(), x);
        auto start = lower;
        auto end = lower;
        int left = k;
        vector<int> ans;
        
        if (lower == arr.begin()) {
            ans.insert(ans.begin(), lower, lower+k);
        } else if (lower == arr.end()) {
            ans.insert(ans.begin(), &arr.back()-k+1, &arr.back()+1);
        } else {
            while (lower != arr.begin() && left > 0) {
                if (end == arr.end()) {
                    ans.insert(ans.begin(), &arr.back()-k+1, &arr.back()+1);
                    return ans;
                } else {
                    if (abs(*(lower-1)-x) <= abs(*(end)-x)) {
                        lower -= 1;
                    } else {
                        end += 1;
                    }
                    left -= 1;
                }
            }
            ans.insert(ans.begin(), lower, lower+k);
            return ans;
        }
        return ans;
    }
};