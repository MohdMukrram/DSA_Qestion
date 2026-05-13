    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = 1 + min(a, b);
            int high = limit + max(a, b);
            int sum = a + b;

            // initially every pair needs 2 moves
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // target sums from low to high need only 1 move
            diff[low] -= 1;
            diff[high + 1] += 1;

            // current sum needs 0 moves
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            moves += diff[s];
            ans = min(ans, moves);
        }

        return ans;
    }