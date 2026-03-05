    #include<iostream>
    #include<algorithm>
    using namespace std;

    int minOperations(string s) {
        int n = s.size();
        int count1 = 0;  // starting with '0'
        int count2 = 0;  // starting with '1'

        for(int i = 0; i < n; i++) {
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if(s[i] != expected1) count1++;
            if(s[i] != expected2) count2++;
        }

        return min(count1, count2);
    }

    int main(){
        string s;
        cin>>s;

        cout<<minOperations(s)<<endl;

    }