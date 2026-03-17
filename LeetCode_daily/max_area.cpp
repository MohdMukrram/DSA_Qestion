#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> height(n, 0);
        int ans = 0;

        for(int i = 0; i < m; i++) {

            // build histogram
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0)
                    height[j] = 0;
                else
                    height[j] += 1;
            }

            // copy and sort
            vector<int> temp = height;
            sort(temp.begin(), temp.end(), greater<int>());

            // compute max area
            for(int j = 0; j < n; j++) {
                ans = max(ans, temp[j] * (j + 1));
            }
        }

        return ans;
    }