#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<int> v;
        vector<vector<int> > ans;
        unordered_set<vector<int>, VectorHash> s;
        unordered_map<int, int> m;
        
        int n = nums.size();
        int left, right, sum;
        
        if (n < 3) return ans;
        
        for (int i = 0; i < n; i++) {
            if (m[nums[i]] < 3) {
                v.push_back(nums[i]);
                m[nums[i]] += 1;
            }
        }
        
        sort(v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++) {
            sum = 0 - v[i];
            left = i + 1;
            right = v.size() - 1;
            
            while (left < right) {
                if (v[left] + v[right] == sum) {
                    s.insert(vector<int>{v[i], v[left], v[right]});
                    left += 1;
                } else if (v[left] + v[right] > sum) right -= 1;
                else left += 1;
            }
        }
        
        for (auto i : s) ans.push_back(i);
        
        return ans;
    }
};