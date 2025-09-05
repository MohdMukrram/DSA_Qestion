#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
         this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* construct(int arr[], int n ){
        queue<Node*> q;
        Node* root = new Node(arr[0]);
        q.push(root);
        int i = 1;
        int j = 2;
        while(q.size()>0 && i<n){
            Node* temp = q.front();
            q.pop();
            Node* l;
            Node* r;
            if(arr[i]!=INT_MIN) l = new Node(arr[i]);
            else l = NULL;
            if(j!=n && arr[j]!=INT_MIN) r = new Node(arr[j]);
            else r = NULL;

            temp->left = l;
            temp->right = r;

            if(l!=NULL) q.push(l);
            if(r!=NULL) q.push(r);
            i+=2;
            j+=2;
        }
        return root;
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}
void nthLevel (Node* root, int curr , int level){
    if(root==NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return;
    }
    nthLevel(root->left,curr+1,level);
    nthLevel(root->right,curr+1,level);
}
void levelOrder(Node* root){
    int n = level(root);
    for(int i=1;i<=n;i++){
        nthLevel(root, 1, i);
        cout<<endl;
    }
    
}
void HorLevel(Node* root, int& minLevel, int& maxLevel, int Level){
    if(root==NULL) return;
    minLevel = min(minLevel,Level);
    maxLevel = max(maxLevel,Level);
    HorLevel(root->left,minLevel,maxLevel,Level-1);
    HorLevel(root->right,minLevel,maxLevel,Level+1);
}
void topview(vector<int>& top, Node* root, int Level){
    if(root==NULL) return;
    if(top[Level]==INT_MIN) top[Level] = root->val;
    topview(top,root->left,Level-1);
    topview(top,root->right,Level+1);
}
int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,9,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    int minLevel = 0;
    int maxLevel = 0;
    HorLevel(root,minLevel,maxLevel,0);
    cout<<minLevel<<" "<<maxLevel<<endl;
    int horLevel = maxLevel - minLevel + 1;
    vector<int> top(horLevel,INT_MIN);
    topview(top,root,-minLevel);
    for(int i=0;i<top.size();i++){
        cout<<top[i]<<" ";
    }
}