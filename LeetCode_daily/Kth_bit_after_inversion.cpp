    #include<iostream>
    #include<algorithm>
    using namespace std;
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }

        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1;i<n;i++){
            string temp = invert(s);
            reverse(temp.begin(), temp.end());
            s = s + "1" + temp;
        }
        return s[k-1];
    }

    int main(){
        int n,k;
        cin>>n>>k;

        cout<<findKthBit(n,k);
    }