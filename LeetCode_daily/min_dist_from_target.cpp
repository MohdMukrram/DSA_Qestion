    #include<iostream>
    #include<vector>
    using namespace std;

    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                mn = min(mn,abs(i-start));
            }
        }

        return mn;
    }
    