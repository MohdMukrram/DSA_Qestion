    #include<iostream>
    #include<vector>
    using namespace std;

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        // Since numbers are between 1 and n, an array of size n + 1 works perfectly
        vector<int> freq(n + 1, 0);
        int common_count = 0;

        for (int i = 0; i < n; ++i) {
            // Check element from array A
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common_count++;
            }

            // Check element from array B
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common_count++;
            }

            C[i] = common_count;
        }

        return C;
    }