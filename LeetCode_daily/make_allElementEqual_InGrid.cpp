    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        int rem = grid[0][0] % x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] % x != rem) return -1;
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(),arr.end());

        int median = arr[arr.size()/2];
        int ops = 0;
        for(int i=0;i<arr.size();i++){
            ops += abs(arr[i] - median)/x;
        }

        return ops;

    }