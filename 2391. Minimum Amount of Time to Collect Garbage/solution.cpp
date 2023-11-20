class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        
        // calculate prefix
        for (int i = 1; i < travel.size(); i++) {
            travel[i] = travel[i-1] + travel[i];
        }

        int paper_truck = 0, glass_truck = 0, metal_truck = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (auto type : garbage[i]) {
                ans += 1;
                if (type == 'G') {
                    glass_truck = i;
                } else if (type == 'P') {
                    paper_truck = i;
                } else {
                    metal_truck = i;
                }
            }
        }
        if (glass_truck > 0) ans += travel[glass_truck - 1];
        if (metal_truck > 0) ans += travel[metal_truck - 1];
        if (paper_truck > 0) ans += travel[paper_truck - 1];
        

        return ans;
    }
};
