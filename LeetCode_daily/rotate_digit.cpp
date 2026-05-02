    #include<iostream>
    #include<vector>
    #include<string>
    #include<algorithm>
    using namespace std;

    int dp[5][2][2];

    int solve(string &s, int pos, bool tight, bool changed) {
        if (pos == s.size())
            return changed; // valid only if at least one digit changed

        if (dp[pos][tight][changed] != -1)
            return dp[pos][tight][changed];

        int limit = tight ? (s[pos] - '0') : 9;
        int res = 0;

        for (int d = 0; d <= limit; d++) {
            // skip invalid digits
            if (d == 3 || d == 4 || d == 7) continue;

            bool next_changed = changed || (d == 2 || d == 5 || d == 6 || d == 9);
            bool next_tight = tight && (d == limit);

            res += solve(s, pos + 1, next_tight, next_changed);
        }

        return dp[pos][tight][changed] = res;
    }

    int rotatedDigits(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, true, false);
    }