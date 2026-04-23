    #include<iostream>
    #include<vector>
    #include<unordered_map>
    #include<algorithm>
    using namespace std;

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> res(n, 0);

        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int k = pos.size();

            // prefix sum
            vector<long long> prefix(k, 0);
            prefix[0] = pos[0];
            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + pos[i];
            }

            for (int i = 0; i < k; i++) {
                long long left = 0, right = 0;

                if (i > 0)
                    left = (long long)pos[i] * i - prefix[i - 1];

                if (i < k - 1)
                    right = (prefix[k - 1] - prefix[i]) - (long long)pos[i] * (k - i - 1);

                res[pos[i]] = left + right;
            }
        }

        return res;
    }