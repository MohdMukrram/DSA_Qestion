#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

    int solve(vector<int>& arr , int i ,int j , vector<vector<int>>& dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i;k<j;k++){
            ans = min(ans,solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + arr[i-1] * arr[k] *arr[j]);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(arr,1,n-1,dp);
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr;
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<matrixMultiplication(arr)<<endl;
        
    }