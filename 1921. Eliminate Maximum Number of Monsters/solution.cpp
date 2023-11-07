class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int ans = 1;
        for (int i = 0; i < dist.size(); i++) {
            dist[i] = ceil(1.0 * dist[i] / speed[i]);
        }
        
        sort(dist.begin(), dist.end());
        
        for (; ans < dist.size() and ans < dist[ans]; ans++);
        
        return ans;
    }
};
