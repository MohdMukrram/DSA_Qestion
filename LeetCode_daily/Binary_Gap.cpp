#include<iostream>
#include<algorithm>
using namespace std;

int binaryGap(int n) {
        int lastPos = -1;   // position of previous 1
        int maxDist = 0;
        int pos = 0;        // current bit position
        
        while (n > 0) {
            if (n & 1) { // if current bit is 1
                if (lastPos != -1) {
                    maxDist = max(maxDist, pos - lastPos);
                }
                lastPos = pos;
            }
            n >>= 1; // move to next bit
            pos++;
        }
        
        return maxDist;
    }

    int main(){
        int n;
        cin>>n;

        cout<<binaryGap(n)<<endl;
    }