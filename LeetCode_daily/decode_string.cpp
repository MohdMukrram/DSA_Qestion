    #include<iostream>
    #include<vector>
    using namespace std;

    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        // Traverse diagonals directly without building matrix
        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;

            while (i < rows && j < cols) {
                result += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }