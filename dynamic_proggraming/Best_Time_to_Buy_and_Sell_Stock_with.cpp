#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& arr , int i , int buy , vector<vector<int>>& dp){
        if(i>=arr.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        if(!buy){
            return dp[i][buy] = max(-arr[i] + solve(arr,i+1,1,dp) , 0 + solve(arr,i+1,0,dp));
        }
        else return dp[i][buy] = max(arr[i] + solve(arr,i+2,0,dp) , 0 + solve(arr,i+1,1,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(prices,0,0,dp);
    }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxProfit(arr);
}