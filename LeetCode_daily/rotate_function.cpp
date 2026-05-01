    #include<iostream>
    #include<vector>
    using namespace std;

    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, f = 0;

        // compute sum and F(0)
        for(int i = 0; i < n; i++){
            sum += nums[i];
            f += (long long)i * nums[i];
        }

        long long ans = f;

        // compute F(k) using recurrence
        for(int k = 1; k < n; k++){
            f = f + sum - (long long)n * nums[n - k];
            ans = max(ans, f);
        }

        return (int)ans;
    }