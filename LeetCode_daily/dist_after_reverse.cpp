    #include<iostream>
    #include<algorithm>
    using namespace std;

    int mirrorDistance(int n) {
        int rev = 0;
        int mul = 1;
        int m = n;
        while(m>0){
            int digi = m%10;
            m /= 10;
            rev = rev * 10 + digi;
        }
        return abs(n-rev);
    }