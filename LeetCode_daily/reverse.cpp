#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        // Loop for half of the rows in the square
        for (int i = 0; i < k / 2; i++) {
            
            // Loop through columns of the square
            for (int j = y; j < y + k; j++) {
                
                // Swap top row with bottom row
                swap(grid[x + i][j], grid[x + k - 1 - i][j]);
            }
        }
        
        return grid;
    }