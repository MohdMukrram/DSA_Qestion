    #include<iostream>
    #include<vector>
    #include<climits>
    #include<algorithm>
    using namespace std;

    int n;
    vector<int> dp;

    int solve(int i, vector<int>& arr, int k) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int maxVal = 0;
        int best = 0;

        // Try partitions of length 1 → k
        for (int len = 1; len <= k && i + len - 1 < n; len++) {
            maxVal = max(maxVal, arr[i + len - 1]);

            int sum = maxVal * len + solve(i + len, arr, k);

            best = max(best, sum);
        }

        return dp[i] = best;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n, -1);
        return solve(0, arr, k);
    }

    int main(){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr;
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }

        cout<<maxSumAfterPartitioning(arr,k)<<endl;
        
    }