class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx);
        int y = abs(sy - fy);
        if (!x and !y and t == 1) return false;
        
        int ans = 0;
        if (x > y) ans = (x - y) + y;
        else if (y > x) ans = (y - x) + x;
        else ans = x;
        
        if (ans > t) return false;
        else return true;
    }
};
