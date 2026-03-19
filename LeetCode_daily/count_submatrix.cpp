#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pref(n, vector<int>(m, 0));
        vector<vector<int>> countX(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                int x = (grid[i][j] == 'X') ? 1 : 0;

                pref[i][j] = val;
                countX[i][j] = x;

                if(i > 0){
                    pref[i][j] += pref[i-1][j];
                    countX[i][j] += countX[i-1][j];
                }
                if(j > 0){
                    pref[i][j] += pref[i][j-1];
                    countX[i][j] += countX[i][j-1];
                }
                if(i > 0 && j > 0){
                    pref[i][j] -= pref[i-1][j-1];
                    countX[i][j] -= countX[i-1][j-1];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pref[i][j] == 0 && countX[i][j] > 0){
                    ans++;
                }
            }
        }

        return ans;
    }
