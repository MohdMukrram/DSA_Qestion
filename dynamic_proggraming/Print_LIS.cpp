#include<iostream>
#include<vector>
using namespace std;
vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n,1) , prev(n,-1);
        
        int mx = 0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j] && dp[j] +1 > dp[i]){
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
            ans.push_back(arr[mx]);
            mx = prev[mx];
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> ans = getLIS(arr);
        for(int x : ans ) cout<<x <<" "; 
    }