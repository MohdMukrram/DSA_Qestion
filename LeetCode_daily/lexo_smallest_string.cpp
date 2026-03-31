    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string word(n + m - 1, '?');

        // Step 1: Apply 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != '?' && word[i + j] != str2[j])
                        return "";
                    word[i + j] = str2[j];
                }
            }
        }

        // Step 2: Fill '?'
        for (char &c : word) {
            if (c == '?') c = 'a';
        }

        // Step 3: Handle 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool fixed = false;

                    // Try all positions to break safely
                    for (int j = m - 1; j >= 0 && !fixed; j--) {
                        char original = word[i + j];

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == str2[j]) continue;

                            word[i + j] = c;

                            // Check ALL 'T' constraints again
                            bool ok = true;
                            for (int k = 0; k < n && ok; k++) {
                                if (str1[k] == 'T') {
                                    for (int x = 0; x < m; x++) {
                                        if (word[k + x] != str2[x]) {
                                            ok = false;
                                            break;
                                        }
                                    }
                                }
                            }

                            if (ok) {
                                fixed = true;
                                break;
                            }
                        }

                        if (!fixed) word[i + j] = original;
                    }

                    if (!fixed) return "";
                }
            }
        }

        return word;
    }