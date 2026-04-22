    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for (auto &q : queries) {
            for (auto &d : dictionary) {
                int diff = 0;

                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i]) {
                        diff++;
                        if (diff > 2) break; // prune early
                    }
                }

                if (diff <= 2) {
                    ans.push_back(q);
                    break; // move to next query
                }
            }
        }

        return ans;
    }