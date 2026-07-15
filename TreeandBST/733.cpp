#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        int m = image.size();
        int n = image[0].size();

        if (sr < 0 || sr >= m || sc < 0 || sc >= n)
            return;

        if (image[sr][sc] != oldColor)
            return;

        image[sr][sc] = newColor;

        dfs(image, sr + 1, sc, oldColor, newColor);
        dfs(image, sr - 1, sc, oldColor, newColor);
        dfs(image, sr, sc + 1, oldColor, newColor);
        dfs(image, sr, sc - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:\n";
    for (auto &row : ans) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
