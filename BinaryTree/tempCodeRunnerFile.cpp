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