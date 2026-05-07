    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        // Build suffix minimum array
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        vector<int> ans(n);

        int start = 0;
        int prefixMax = nums[0];

        for (int i = 0; i < n - 1; i++) {
            prefixMax = max(prefixMax, nums[i]);

            // Component ends here
            if (prefixMax <= suffixMin[i + 1]) {

                int componentMax = prefixMax;

                for (int j = start; j <= i; j++) {
                    ans[j] = componentMax;
                }

                start = i + 1;

                if (start < n)
                    prefixMax = nums[start];
            }
        }

        // Handle last component
        int componentMax = nums[start];

        for (int i = start; i < n; i++) {
            componentMax = max(componentMax, nums[i]);
        }

        for (int i = start; i < n; i++) {
            ans[i] = componentMax;
        }

        return ans;
    }