    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include <functional>
    using namespace std;
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // Step 1: Validate diagonal
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }
        
        // Step 2: Union-Find setup
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };
        
        auto unite = [&](int a, int b) {
            parent[find(a)] = find(b);
        };
        
        // Merge indices where lcp[i][j] > 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }
        
        // Step 3: Assign characters (smallest lexicographically)
        vector<char> groupChar(n, 0);
        char curr = 'a';
        string word(n, ' ');
        
        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (groupChar[root] == 0) {
                if (curr > 'z') return ""; // only 26 letters allowed
                groupChar[root] = curr++;
            }
            word[i] = groupChar[root];
        }
        
        // Step 4: Verify LCP matrix
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i + 1 < n && j + 1 < n)
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    else
                        dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
                
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }
        
        return word;
    }