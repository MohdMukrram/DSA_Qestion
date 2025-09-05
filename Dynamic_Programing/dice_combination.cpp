#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define mod 1000000007
using namespace std;

vector<long long>dp(1000005,-1);

long long f(int n){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    long long sum = 0;
    for(int i=1;i<=6;i++){
        if(n-i < 0) break;
        sum = (sum%mod + f(n-i) % mod)%mod;
    }
    return dp[n] = sum % mod;
}
long long bottom_up(int n){
    dp[0] = 1;
    for(int k =1;k<=n;k++){
        long long sum = 0;
        for(int i=1;i<=6;i++){
            if(k-i < 0) break;
            sum = (sum%mod + dp[k-i]%mod)%mod;
        }
        dp[k] = sum%mod;
    }
    return dp[n];
}
int main(){
    int n;
    cout<<"enter the Number::";
    cin>>n;
    cout<<f(n)<<endl;
    cout<<bottom_up(n)<<endl;
}
