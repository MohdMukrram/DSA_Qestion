    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Apply gravity (right side)
        for (int i = 0; i < m; i++) {
            int emptyPos = n - 1;

            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    emptyPos = j - 1;
                } 
                else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][emptyPos]);
                    emptyPos--;
                }
            }
        }

        // Step 2: Rotate 90° clockwise
        vector<vector<char>> result(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return result;
    }