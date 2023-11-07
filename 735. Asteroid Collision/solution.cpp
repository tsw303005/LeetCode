class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        vector<int> ans;
        
        for (auto& asteroid : asteroids) {
            if (asteroid < 0 and s.empty()) ans.push_back(asteroid);
            else if (asteroid > 0) s.push_back(asteroid);
            else {
                while (!s.empty() and s.back() < abs(asteroid)) s.pop_back();
                if (!s.empty() and s.back() == abs(asteroid)) s.pop_back();
                else if (s.empty()) ans.push_back(asteroid);
            }
        }
        
        for (auto& e : s) ans.push_back(e);
        
        return ans;
    }
};
