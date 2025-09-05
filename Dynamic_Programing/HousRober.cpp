#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int Rob(vector<int>& arr,int i,vector<int>& dp){
        if(i == arr.size() - 1) return arr[i];
        if(i == arr.size() - 2) return max(arr[i],arr[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(arr[i] + Rob(arr,i+2,dp) , Rob(arr,i+1,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(101,-1);
        return Rob(nums,0,dp);
        
    }
};