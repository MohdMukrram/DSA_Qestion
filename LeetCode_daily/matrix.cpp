#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                set<int> st;

                // collect elements
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        st.insert(grid[x][y]);
                    }
                }

                if (st.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }

                int mini = INT_MAX;

                auto it = st.begin();
                auto prev = it;
                ++it;

                // compute min difference
                while (it != st.end()) {
                    mini = min(mini, *it - *prev);
                    prev = it;
                    ++it;
                }

                ans[i][j] = mini;
            }
        }

        return ans;
    }
