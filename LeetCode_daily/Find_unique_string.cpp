    #include<iostream>
    #include<vector>
    #include<unordered_set>
    using namespace std;
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        for(string s : nums) st.insert(s);

        string s = nums[0];
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            s[i] = (s[i] == '0') ? '1' : '0';
            if(!st.count(s)) return s;
            else s[i] = ch;
        }

        if(!st.count(s)) return s;
        return "";
    }

    int main(){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        cout<<findDifferentBinaryString(arr);

    }