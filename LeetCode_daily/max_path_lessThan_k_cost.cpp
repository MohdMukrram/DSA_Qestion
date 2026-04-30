    #include<iostream>
    #include<vector>
    using namespace std;

    int n, m;
    const int NEG = -1e8;

    int solve(vector<vector<int>>& grid, int i, int j, int k, int c,vector<vector<vector<int>>>& dp) {

        if(i >= n || j >= m) return NEG;

        int newcost = c + (grid[i][j] == 0 ? 0 : 1);
        if(newcost > k) return NEG;

        if(i == n-1 && j == m-1) return grid[i][j];

        if(dp[i][j][newcost] != -1) return dp[i][j][newcost];

        int right = solve(grid, i, j+1, k, newcost, dp);
        int down  = solve(grid, i+1, j, k, newcost, dp);

        int mx = max(right, down);

        if(mx == NEG) return dp[i][j][newcost] = NEG;

        return dp[i][j][newcost] = grid[i][j] + mx;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans = solve(grid, 0, 0, k, 0, dp);

        return (ans == NEG) ? -1 : ans;
    }