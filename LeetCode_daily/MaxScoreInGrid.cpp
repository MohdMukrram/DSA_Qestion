    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    long long maximumScore(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        // prefix sum: pre[j][i] = sum of column (j-1) from row 0 to i-1
        vector<vector<long long>> pre(m + 2, vector<long long>(n + 1, 0));

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                pre[j + 1][i + 1] = pre[j + 1][i] + a[i][j];
            }
        }

        // dp[j][i][state]
        // j = columns processed
        // i = height of column j
        // state = 0/1 (transition optimization states)
        vector<vector<vector<long long>>> dp(
            m + 1, vector<vector<long long>>(n + 1, vector<long long>(2, 0))
        );

        // mx[j] = best value up to column j
        vector<long long> mx(m + 1, 0);

        long long ans = 0;

        for (int j = 1; j <= m; j++) {
            for (int i = 0; i <= n; i++) {

                // Case: start fresh / skip adjacency using mx
                dp[j][i][0] = max(dp[j][i][0],
                    pre[j - 1][i] + pre[j + 1][i] + (j >= 3 ? mx[j - 3] : 0LL)
                );

                for (int k = 0; k <= n; k++) {

                    if (k < i) {
                        // previous height smaller
                        dp[j][i][0] = max(dp[j][i][0],
                            dp[j - 1][k][0]
                            - pre[j][k]
                            + (pre[j - 1][i] - pre[j - 1][k])
                            + pre[j + 1][i]
                        );
                    } else {
                        // previous height greater or equal
                        dp[j][i][1] = max(dp[j][i][1],
                            dp[j - 1][k][1]
                            - pre[j][i]
                            + pre[j + 1][i]
                        );
                    }

                    // skip one column (handle non-adjacent interaction)
                    if (j >= 2) {
                        dp[j][i][0] = max(dp[j][i][0],
                            dp[j - 2][k][1]
                            - pre[j - 1][k]
                            + pre[j - 1][max(k, i)]
                            + pre[j + 1][i]
                        );
                    }
                }

                // propagate best state
                dp[j][i][1] = max(dp[j][i][1], dp[j][i][0]);

                // update global max trackers
                mx[j] = max({mx[j], mx[j - 1], dp[j][i][1]});
                ans = max(ans, dp[j][i][1]);
            }
        }

        return ans;
    }