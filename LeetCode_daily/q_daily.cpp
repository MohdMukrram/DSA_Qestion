    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<unordered_map>
    using namespace std;

    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastIndex;
        int ans = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            int x = nums[j];

            // check if some previous number had reverse = x
            if (lastIndex.count(x)) {
                ans = min(ans, j - lastIndex[x]);
            }

            // store reverse of current number
            int rev = reverseNum(x);
            lastIndex[rev] = j;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }