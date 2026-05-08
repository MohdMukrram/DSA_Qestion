    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<queue>
    using namespace std;

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        // SPF = smallest prime factor
        vector<int> spf(mx + 1);
        for (int i = 0; i <= mx; i++) spf[i] = i;

        if (mx >= 0) spf[0] = 0;
        if (mx >= 1) spf[1] = 1;

        for (long long i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        auto isPrime = [&](int x) {
            return x >= 2 && spf[x] == x;
        };

        // prime p -> all indices whose nums[index] divisible by p
        vector<vector<int>> divisible(mx + 1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];
                divisible[p].push_back(i);

                while (x % p == 0) x /= p;
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            // adjacent step: i - 1
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            // adjacent step: i + 1
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            // prime teleportation
            int val = nums[i];
            if (isPrime(val)) {
                for (int j : divisible[val]) {
                    if (dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }

                // important: process this prime only once
                divisible[val].clear();
            }
        }

        return dist[n - 1];
    }