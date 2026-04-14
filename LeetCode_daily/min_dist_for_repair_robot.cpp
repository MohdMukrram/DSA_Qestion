    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    long long dp[105][10005];

    long long solve(int i, int j, vector<int>& robot, vector<int>& slots) {
        if (i == robot.size()) return 0;
        if (j == slots.size()) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        // option 1: skip slot
        long long skip = solve(i, j + 1, robot, slots);

        // option 2: assign robot[i] to slot[j]
        long long take = abs(robot[i] - slots[j]) + solve(i + 1, j + 1, robot, slots);

        return dp[i][j] = min(skip, take);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> slots;

        for (auto &f : factory) {
            int pos = f[0], limit = f[1];
            while (limit--) {
                slots.push_back(pos);
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, robot, slots);
    }