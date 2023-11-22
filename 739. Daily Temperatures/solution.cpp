const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        using Pair = pair<int, int>;
        stack<Pair> s;
        vector<int> ans(temperatures.size());
        
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty()) {
                auto &top = s.top();
                if (top.first >= temperatures[i]) {
                    break;
                }

                ans[top.second] = i - top.second;
                s.pop();
            }

            s.push({temperatures[i], i});
        }
        
        while (!s.empty()) {
            ans[s.top().second] = 0;
            s.pop();
        }
        
        return ans;
    }
};
