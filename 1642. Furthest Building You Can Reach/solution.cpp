class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        int count = 0;
        int height_dist;
        int biggest;
        priority_queue<int> PQ;
        
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] <= heights[i-1]) ans = i; // go to next building directly
            else { // need to consume some bricks or a ladder
                height_dist = heights[i] - heights[i-1];
                PQ.push(height_dist);

                if (count + height_dist > bricks) { // if bricks is not enough, pick the longest dist from queue
                    if (!ladders) return ans; // if no ladder, find the answer

                    biggest = PQ.top(); // get the longest dist from queue
                    PQ.pop();
                    
                    // update count and ladder
                    count -= biggest;
                    count += height_dist;
                    ladders -= 1;
                } else {
                    count += height_dist;
                }
                ans = i; // update the answer;
            }
        }
        
        return ans;
    }
};
