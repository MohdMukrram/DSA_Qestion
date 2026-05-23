#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int idx = 0;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                count++;
                idx = i;
            }
        }

        if(count > 1) return false;
        if(idx == 0) return true;

        return nums[n-1] <= nums[0];
    }