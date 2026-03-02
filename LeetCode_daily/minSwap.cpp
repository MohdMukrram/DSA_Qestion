#include<iostream>
#include<vector>
using namespace std;

int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);
        
        // Step 1: Count trailing zeros in each row
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            trailingZeros[i] = count;
        }
        
        int swaps = 0;
        
        // Step 2: Fix each row position
        for(int i = 0; i < n; i++) {
            int needed = n - i - 1;  // required trailing zeros
            int j = i;
            
            // Find a row with enough trailing zeros
            while(j < n && trailingZeros[j] < needed) {
                j++;
            }
            
            // If no such row exists
            if(j == n) return -1;
            
            // Bring that row up using adjacent swaps
            while(j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }

    int main(){
        int n;
        cin>>n;

        vector<vector<int>> arr(n,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }

        cout<<minSwaps(arr)<<endl;
    }