#include<iostream>
using namespace std;

    bool checkOnesSegment(string s) {
        int n = s.size();
        for(int i=1;i<n;i++){
            if(s[i] == '1' && s[i-1] == '0'){
                return false;
            }
        }
        return true;
    }

    int main(){
        string s;
        cin>>s;

        if(checkOnesSegment(s)) cout<<"True"<<endl;
        else cout<<"False"<<endl;
    }