#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int dist = INT_MAX;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int d = abs(i - j) + abs(j - k) + abs(k - i);
                        dist = min(dist, d);
                    }
                }
            }
        }

        return dist == INT_MAX ? -1 : dist;
    }