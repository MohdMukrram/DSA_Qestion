#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mod = 1e9 + 7;
    
    pair<long long, long long> dp[16][16];
    bool vis[16][16];
    
    pair<long long, long long> solve(int i, int j, vector<vector<int>>& grid) {
        
        // base case
        if (i == 0 && j == 0) {
            return {grid[0][0], grid[0][0]};
        }
        
        if (vis[i][j]) return dp[i][j];
        
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        
        // from top
        if (i > 0) {
            auto p = solve(i - 1, j, grid);
            maxi = max(maxi, max(p.first * grid[i][j], p.second * grid[i][j]));
            mini = min(mini, min(p.first * grid[i][j], p.second * grid[i][j]));
        }
        
        // from left
        if (j > 0) {
            auto p = solve(i, j - 1, grid);
            maxi = max(maxi, max(p.first * grid[i][j], p.second * grid[i][j]));
            mini = min(mini, min(p.first * grid[i][j], p.second * grid[i][j]));
        }
        
        vis[i][j] = true;
        return dp[i][j] = {maxi, mini};
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));
        
        auto ans = solve(grid.size() - 1, grid[0].size() - 1, grid);
        
        if (ans.first < 0) return -1;
        return ans.first % mod;
    }