#include<iostream>
using namespace std;

    int numSteps(string s) {
        int steps = 0, carry = 0;
        
        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }
        
        return steps + carry;
    }

    int main(){
        string s;
        cin>>s;

        cout<<numSteps(s)<<endl;

    }