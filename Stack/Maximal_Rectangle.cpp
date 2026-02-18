#include<iostream>
#include<vector>
#include<stack>
using namespace std;
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int mxArea = 0;
        int n = heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                mxArea = max(mxArea , heights[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int nse = n;
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            mxArea = max(mxArea , heights[ele] * (nse - pse - 1));
        }
        return mxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int mx = 0; 
        vector<vector<int>> preArr(n,vector<int>(m));

        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                if(matrix[i][j] == '0') sum = 0;
                else sum += 1;
                preArr[i][j] = sum;
            }
        }

        for(int i=0;i<n;i++){
            mx = max(mx,largestRectangleArea(preArr[i]));
        }
        return mx;
    }

int main(){
    int n;
    cin>>n;

    vector<vector<char>> arr(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<maximalRectangle(arr)<<endl;
}