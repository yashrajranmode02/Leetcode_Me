
class Solution {
    // root=esme jake search karo
    // ignore= meko ignore karo
public:
bool F2(TreeNode* root,TreeNode* ignore,int k){
    if(!root ||root==ignore)return 0;
    if(root->val==k)return 1;
    return F2(root->left,ignore,k)||F2(root->right,ignore,k);
}
bool F(TreeNode* root,TreeNode* ignore,int &k,int k2){
    if(!ignore)return 0;
    if(F2(root,ignore,(k2-ignore->val)))return 1;
   return  F(root,ignore->left,k,k2)||F(root,ignore->right,k,k2);
}
    bool findTarget(TreeNode* root, int k) {
        
       return F(root,root,k,k);
    }
};