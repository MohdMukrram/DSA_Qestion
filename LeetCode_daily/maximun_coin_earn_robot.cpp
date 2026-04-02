    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    int m, n;
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int j, int k, vector<vector<int>>& coins) {
        if (i >= m || j >= n) return -1e9;
        
        if (i == m-1 && j == n-1) {
            if (coins[i][j] >= 0) return coins[i][j];
            else {
                if (k > 0) return 0;
                else return coins[i][j];
            }
        }
        
        if (dp[i][j][k] != -1e9) return dp[i][j][k];
        
        int ans = -1e9;
        
        int right = solve(i, j+1, k, coins);
        int down  = solve(i+1, j, k, coins);
        
        int bestNext = max(right, down);
        ans = coins[i][j] + bestNext;
        
        // Case 2: neutralize if negative
        if (coins[i][j] < 0 && k > 0) {
            int rightN = solve(i, j+1, k-1, coins);
            int downN  = solve(i+1, j, k-1, coins);
            
            int bestNeutral = max(rightN, downN);
            
            ans = max(ans, bestNeutral);
        }
        
        return dp[i][j][k] = ans;
    }
    
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        
        dp.assign(m, vector<vector<int>>(n, vector<int>(3, -1e9)));
        
        return solve(0, 0, 2, coins);
    }