#include<iostream>
#include<algorithm>
using namespace std;

    static inline int ceilDiv(int a, int b) {
        return (a + b - 1) / b;
    }

    int minOperations(string s, int k) {
        int n = (int)s.size();
        int zero = 0;
        for (char c : s) zero += (c == '0');

        if (zero == 0) return 0;

        if (n == k) {
            if (zero == n) return 1;   // all 0 -> flip all -> all 1
            return -1;                 // mixed stays mixed forever
        }

        int base = n - k;              // > 0
        int one  = n - zero;

        int need0_by_k = ceilDiv(zero, k);

        int ans = INT_MAX;

        // odd i case
        if ( (k & 1) == (zero & 1) ) {
            int odd = max(need0_by_k, ceilDiv(one, base));
            if ((odd & 1) == 0) ++odd;          // round up to odd
            ans = min(ans, odd);
        }

        // even i case
        if ((zero & 1) == 0) {
            int even = max(need0_by_k, ceilDiv(zero, base));
            if (even & 1) ++even;               // round up to even
            ans = min(ans, even);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
    
    int main(){
        string s;
        cin>>s;
        int k;
        cin>>k;
        cout<<minOperations(s,k)<<endl;

    }