    #include<iostream>
    #include<vector>
    #include<climits>
    #include<algorithm>
    using namespace std;

    vector<vector<int>> dp;
    vector<vector<bool>> isPal;
    int n;

    int solve(int i, string &s) {
        // Base case → no cut needed if at end
        if (i == n) return 0;

        if (dp[i][0] != -1) return dp[i][0];

        int minCuts = INT_MAX;

        // Try all partitions
        for (int j = i; j < n; j++) {
            if (isPal[i][j]) {
                int cuts = 1 + solve(j + 1, s);
                minCuts = min(minCuts, cuts);
            }
        }

        return dp[i][0] = minCuts;
    }

    int minCut(string s) {
        n = s.size();

        dp.assign(n, vector<int>(1, -1));
        isPal.assign(n, vector<bool>(n, false));

        // Precompute palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // subtract 1 because last partition doesn't need a cut
        return solve(0, s) - 1;
    }

    int main(){
        string s;
        cin>>s;

        cout<<minCut(s)<<endl;
        
    }