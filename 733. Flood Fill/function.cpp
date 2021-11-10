#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int row, col;
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int startColor) {
        image[sr][sc] = newColor;
        if (sr-1 >= 0 && image[sr-1][sc] == startColor) dfs(image, sr-1, sc, newColor, startColor);
        if (sr+1 < row && image[sr+1][sc] == startColor) dfs(image, sr+1, sc, newColor, startColor);
        if (sc-1 >= 0 && image[sr][sc-1] == startColor) dfs(image, sr, sc-1, newColor, startColor);
        if (sc+1 < col && image[sr][sc+1] == startColor) dfs(image, sr, sc+1, newColor, startColor);
    }
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int start_color = image[sr][sc];
        if (start_color == newColor) return image;
        
        row = image.size();
        col = image[0].size();
        if (row == 0 || col == 0) return image;
        
        dfs(image, sr, sc, newColor, start_color);
        return image;
    }
};