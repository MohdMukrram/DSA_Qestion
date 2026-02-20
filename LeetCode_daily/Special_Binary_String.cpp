#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

    string makeLargestSpecial(string s) {
        vector<string> parts;
        
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                count++;
            else count--;

            // when balanced → found a special substring
            if (count == 0) {
                // solve inside recursively
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));

                // wrap with outer 1 and 0
                parts.push_back("1" + inner + "0");

                start = i + 1;
            }
        }

        // sort in descending lexicographic order
        sort(parts.begin(), parts.end(), greater<string>());

        // combine all parts
        string result = "";
        for (string &p : parts)
            result += p;

        return result;
    }

    int main(){
        string s;
        cin>>s;
        cout<<makeLargestSpecial(s)<<endl;
    }