    #include<iostream>
    using namespace std;

    bool judgeCircle(string moves) {
        int u = 0, d = 0, l = 0, r = 0;

        for(char c : moves) {
            if(c == 'U') u++;
            else if(c == 'D') d++;
            else if(c == 'L') l++;
            else if(c == 'R') r++;
        }

        return (u == d && l == r);
    }