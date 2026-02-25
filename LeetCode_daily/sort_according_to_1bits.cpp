#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    static bool compare(int a, int b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        
        if (countA == countB)
            return a < b;
        
        return countA < countB;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sortByBits(arr);
}