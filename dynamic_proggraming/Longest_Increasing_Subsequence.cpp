#include<iostream>
#include<vector>
using namespace std;
    int solve(vector<int>& nums, int i, int prevIndex, vector<vector<int>>& dp) {
        
        if(i >= nums.size()) return 0;

        if(dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];

        // Not take
        int notTake = solve(nums, i + 1, prevIndex, dp);

        // Take
        int take = 0;
        if(prevIndex == -1 || nums[i] > nums[prevIndex]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }

        return dp[i][prevIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1, dp);
    }
    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        lengthOfLIS(arr);
    }