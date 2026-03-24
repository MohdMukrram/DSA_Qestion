#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();
        
        // Step 1: Flatten grid
        vector<int> arr;
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val % MOD);
            }
        }
        
        int k = arr.size();
        
        // Step 2: Prefix array
        vector<int> prefix(k, 1);
        for (int i = 1; i < k; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }
        
        // Step 3: Suffix array
        vector<int> suffix(k, 1);
        for (int i = k - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }
        
        // Step 4: Result array
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = (prefix[i] * suffix[i]) % MOD;
        }
        
        // Step 5: Convert back to 2D
        vector<vector<int>> ans(n, vector<int>(m));
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = res[idx++];
            }
        }
        
        return ans;