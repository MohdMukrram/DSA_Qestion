#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> newMat(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                newMat[j][n - 1 - i] = mat[i][j];
            }
        }
        return newMat;
    }

    // Function to check equality
    bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != b[i][j])
                    return false;
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) {
            if (isEqual(mat, target))
                return true;
            mat = rotate(mat);
        }
        return false;
    }