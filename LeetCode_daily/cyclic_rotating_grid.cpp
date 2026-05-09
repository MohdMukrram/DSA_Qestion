    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<queue>
    using namespace std;

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> v;

            int top = l, left = l;
            int bottom = m - 1 - l;
            int right = n - 1 - l;

            // collect clockwise
            for (int j = left; j <= right; j++)
                v.push_back(grid[top][j]);

            for (int i = top + 1; i <= bottom; i++)
                v.push_back(grid[i][right]);

            for (int j = right - 1; j >= left; j--)
                v.push_back(grid[bottom][j]);

            for (int i = bottom - 1; i > top; i--)
                v.push_back(grid[i][left]);

            int len = v.size();
            int rot = k % len;
            int idx = rot;

            // fill clockwise
            for (int j = left; j <= right; j++) {
                grid[top][j] = v[idx];
                idx = (idx + 1) % len;
            }

            for (int i = top + 1; i <= bottom; i++) {
                grid[i][right] = v[idx];
                idx = (idx + 1) % len;
            }

            for (int j = right - 1; j >= left; j--) {
                grid[bottom][j] = v[idx];
                idx = (idx + 1) % len;
            }

            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = v[idx];
                idx = (idx + 1) % len;
            }
        }

        return grid;
    }