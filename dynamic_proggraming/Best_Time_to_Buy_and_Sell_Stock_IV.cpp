#include<iostream>
#include<vector>
using namespace std;
    int solve(vector<int>& arr , int i , int buy , int k , vector<vector<vector<int>>>& dp){
        if(i >= arr.size() || k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        if(!buy){
            return dp[i][buy][k] = max(-arr[i] + solve(arr,i+1,1,k,dp) , 0 + solve(arr,i+1,0,k,dp));
        }
        else{
           return  dp[i][buy][k] = max(arr[i] + solve(arr,i+1,0,k-1,dp) , 0 + solve(arr,i+1,1,k,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(prices,0,0,k,dp);
    }

    int main(){
        int n,k;
        cin>>n;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        maxProfit(k,arr);
    }