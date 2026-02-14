#include<iostream>
#include<vector>
using namespace std;
    int solve(vector<int>& arr , int i , int buy , int fee , vector<vector<int>>& dp){
        if(i>=arr.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(!buy){
            return dp[i][buy] = max(-arr[i] - fee + solve(arr,i+1,1,fee,dp), 0 + solve(arr,i+1,0,fee,dp));
        }
        else{
            return dp[i][buy] = max(arr[i] + solve(arr,i+1,0,fee,dp), 0 + solve(arr,i+1,1,fee,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(prices,0,0,fee,dp);
    }

    int main(){
        int n,fee;
        cin>>n;
        cin>>fee;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        maxProfit(arr,fee);
    }