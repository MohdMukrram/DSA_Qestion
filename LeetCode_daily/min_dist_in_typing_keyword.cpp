    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    int dp[301][27][27];

    // Convert character index (0–25) to (row, col)
    pair<int,int> getPos(int c) {
        return {c / 6, c % 6};
    }

    // Manhattan distance
    int getDist(int a, int b) {
        if (a == 26) return 0; // finger not placed yet
        auto [x1, y1] = getPos(a);
        auto [x2, y2] = getPos(b);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int i, int f1, int f2, string &word) {
        // Base case
        if (i == word.size()) return 0;

        // Memo check
        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        // Option 1: move finger1
        int op1 = getDist(f1, curr) + solve(i + 1, curr, f2, word);

        // Option 2: move finger2
        int op2 = getDist(f2, curr) + solve(i + 1, f1, curr, word);

        // Store and return
        return dp[i][f1][f2] = min(op1, op2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 26, word); // both fingers unused
    }   