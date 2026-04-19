    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i=0,j=0;
        int mx = 0;
        while(i<n && j<m){
            if(i<=j && nums1[i] > nums2[j]) i++;
            else{
                mx = max(mx , j-i);
                j++;
            }
        }
        return mx;
    }