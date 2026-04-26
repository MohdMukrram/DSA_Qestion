    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    int m, n;
        vector<vector<bool>> vis;
        
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid) {
        vis[i][j] = true;
        
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for (auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;
            
            if (grid[ni][nj] != grid[i][j])
                continue;
            
            // If not visited → continue DFS
            if (!vis[ni][nj]) {
                if (dfs(ni, nj, i, j, grid))
                    return true;
            }
            // If visited and NOT parent → cycle found
            else if (ni != pi || nj != pj) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }
        
        return false;
    }