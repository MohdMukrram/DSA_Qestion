#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    vector<string> ans;
    void solve(int n, string curr){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        for(char ch : {'a','b','c'}){
            if(curr.size() > 0 && curr.back() == ch){
                continue;
            }
            curr.push_back(ch);
            solve(n,curr);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        solve(n,"");
        if(ans.size() < k){
            return "";
        }
        return ans[k-1];
    }

    int main(){
        int n,k;
        cin>>n>>k;

        cout<<getHappyString(n,k)<<endl;
    }