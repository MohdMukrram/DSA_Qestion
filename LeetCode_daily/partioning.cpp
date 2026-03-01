#include<iostream>
using namespace std;

int minPartitions(string n) {
        int maxDigit = 0;
        
        for(char c : n) {
            maxDigit = max(maxDigit, c - '0');
            
            // If we ever find 9, we can stop early
            if(maxDigit == 9)
                return 9;
        }
        
        return maxDigit;
    }

    int main(){
        string s;
        cout<<minPartitions(s)<<endl;
    }