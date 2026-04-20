    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int mx = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(colors[j] != colors[i]){
                    mx = max(mx,abs(j-i));
                }
            }
        }

        return mx;
    }