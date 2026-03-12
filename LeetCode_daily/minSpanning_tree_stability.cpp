#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findp(int x, vector<int>& parent){
    if(parent[x]==x) return x;
    return parent[x]=findp(parent[x], parent);
}

bool unite(int a,int b,vector<int>& parent){
    int pa=findp(a,parent);
    int pb=findp(b,parent);

    if(pa==pb) return false;

    parent[pb]=pa;
    return true;
}

bool check(int n, vector<vector<int>>& edges, int k, int X){

    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i]=i;

    int used=0;

    vector<vector<int>> normal;
    vector<vector<int>> upgrade;

    for(auto &e:edges){

        int u=e[0], v=e[1], s=e[2], must=e[3];

        if(must==1){

            if(s<X) return false;

            if(!unite(u,v,parent)) return false;

            used++;
        }
        else{

            if(s>=X) normal.push_back(e);
            else if(2*s>=X) upgrade.push_back(e);
        }
    }

    for(auto &e:normal){
        if(unite(e[0],e[1],parent)) used++;
    }

    int up=0;

    for(auto &e:upgrade){
        if(up>=k) break;

        if(unite(e[0],e[1],parent)){
            used++;
            up++;
        }
    }

    return used==n-1;
}

int maxStability(int n, vector<vector<int>>& edges, int k){

    int l=1,r=200000;
    int ans=-1;

    while(l<=r){

        int mid=(l+r)/2;

        if(check(n,edges,k,mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<vector<int>> edges;

    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a,b,c,d;
        edges.push_back({a,b,c,d});
    }

    cout<<maxStability(n,edges,k);

}