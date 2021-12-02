#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> record(nums.size(), 0);
        int ans = 0;
        record[0] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
          for (int j = i-1; j >= 0; j++) {
            if (nums[i] % nums[j] == 0) {
              record[i] = record[j] + 1;
              ans = (record[ans] < record[i]) ? i : ans;
              break;
            } else if (j == 0) {
              record[i] = 1;
            }
          }
        }
        int flag = 1;
        for (int i = 0; i < nums.size(); i++) {
          if (nums[ans] % nums[i] == 0) {
            if (!flag) {
              cout << ' ';
            } else flag = 0;
            cout << nums[i];
          }
        }
        cout << endl;
    }
};