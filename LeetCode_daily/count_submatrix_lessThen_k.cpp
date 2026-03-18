#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                // Build prefix sum in-place
                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
                
                // Check condition
                if(grid[i][j] <= k) count++;
            }
        }
        
        return count;
    }

int main(){
    int n , m , k;
    cin>>n>>m>>k;

    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    cout<<countSubmatrices(arr,k)<<endl;
}