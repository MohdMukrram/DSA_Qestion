#include<iostream>
#include<vector>
using namespace std;
const long long mod = 1e9 + 7;
vector<long long> arr;
long long mul = 1;
long long add = 0;

long long modInverse(long long x){
    long long res = 1, p = mod - 2;
    while(p){
        if(p & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return res;
}

void append(int val) {
    long long x = (val - add + mod) % mod;
    x = (x * modInverse(mul)) % mod;
    arr.push_back(x);
}

void addAll(int inc) {
    add = (add + inc) % mod;
}

void multAll(int m) {
    mul = (mul * m) % mod;
    add = (add * m) % mod;
}

int getIndex(int idx) {
    if(idx >= arr.size()) return -1;
    return (arr[idx] * mul % mod + add) % mod;
}