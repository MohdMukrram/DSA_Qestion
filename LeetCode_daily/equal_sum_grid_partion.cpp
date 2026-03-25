#include<iostream>
#include<vector>
using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                total += grid[i][j];

        if (total % 2 != 0) return false;
        long long half = total / 2;

        // Try horizontal cuts (between rows)
        long long rowSum = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j)
                rowSum += grid[i][j];
            if (rowSum == half) return true;
        }

        // Try vertical cuts (between columns)
        vector<long long> colSums(m, 0);
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                colSums[j] += grid[i][j];

        long long colAcc = 0;
        for (int j = 0; j < m - 1; ++j) {
            colAcc += colSums[j];
            if (colAcc == half) return true;
        }

        return false;
    }