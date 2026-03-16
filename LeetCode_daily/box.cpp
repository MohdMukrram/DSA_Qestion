#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<int, greater<int>> st;
        
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                
                // area 0 rhombus (single cell)
                st.insert(grid[r][c]);
                
                for(int k = 1; ; k++){
                    
                    if(r-k < 0 || r+k >= m || c-k < 0 || c+k >= n)
                        break;
                    
                    int sum = 0;
                    
                    // top -> right
                    int x = r-k, y = c;
                    for(int i=0;i<k;i++){
                        sum += grid[x+i][y+i];
                    }
                    
                    // right -> bottom
                    x = r; y = c+k;
                    for(int i=0;i<k;i++){
                        sum += grid[x+i][y-i];
                    }
                    
                    // bottom -> left
                    x = r+k; y = c;
                    for(int i=0;i<k;i++){
                        sum += grid[x-i][y-i];
                    }
                    
                    // left -> top
                    x = r; y = c-k;
                    for(int i=0;i<k;i++){
                        sum += grid[x-i][y+i];
                    }
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        
        for(int x : st){
            ans.push_back(x);
            if(ans.size() == 3)
                break;
        }
        
        return ans;
    }
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    getBiggestThree(arr);
}