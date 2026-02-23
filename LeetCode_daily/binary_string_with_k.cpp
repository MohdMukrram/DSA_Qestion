#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        // Total possible binary codes of length k
        int total = 1 << k;
        
        // Quick pruning
        if (n < k + total - 1) return false;
        
        unordered_set<int> seen;
        int hash = 0;
        
        // First window
        for (int i = 0; i < k; i++) {
            hash = (hash << 1) | (s[i] - '0');
        }
        
        seen.insert(hash);
        
        int mask = total - 1; // keeps only last k bits
        
        // Sliding window
        for (int i = k; i < n; i++) {
            hash = ((hash << 1) & mask) | (s[i] - '0');
            seen.insert(hash);
            
            if (seen.size() == total)
                return true;
        }
        
        return seen.size() == total;
    }

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;

    cout<<hasAllCodes(s,k)<<endl;

}