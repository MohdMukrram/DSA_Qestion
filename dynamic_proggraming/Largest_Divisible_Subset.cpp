#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};

        sort(nums.begin(),nums.end());
        vector<int> dp(n,1) , prev(n , -1);
        int mx = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if(dp[i] > dp[mx]){
                mx = i;
            }
        }

        vector<int> ans;
        while(mx != -1){
            ans.push_back(nums[mx]);
            mx = prev[mx];
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> ans = largestDivisibleSubset(arr);
        for(int x : ans ) cout<<x <<" "; 
    }