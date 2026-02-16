    #include<iostream>
    #include<vector>
    #include<climits>
    #include<algorithm>
    using namespace std;

    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if(i + 1 == j) return 0;   // no balloon in between
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        
        for(int k = i + 1; k < j; k++) {
            ans = max(ans,solve(nums, i, k, dp) + solve(nums, k, j, dp) + nums[i] * nums[k] * nums[j]);
        }
        
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // add 1 at beginning and end
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        
        return solve(nums, 0, n+1, dp);
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr;
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<maxCoins(arr)<<endl;
        
    }