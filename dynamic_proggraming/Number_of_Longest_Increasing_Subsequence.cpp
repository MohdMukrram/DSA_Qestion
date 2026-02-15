#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1) , cnt(n,1);
        int mx = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[j] + 1 == dp[i]){
                    cnt[i] += cnt[j];
                }
            }
            mx = max(mx,dp[i]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == mx) count += cnt[i];
        }
        return count;
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<findNumberOfLIS(arr)<<endl;
    }