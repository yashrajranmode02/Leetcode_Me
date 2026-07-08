/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void  D(TreeNode* root, int k,int &ans,vector<int>&a){
    if(!root)return ;
    D(root->left,k,ans,a);
    a.push_back(root->val);
    D(root->right,k,ans,a);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;vector<int>a;
        D(root,k,ans,a);
        return a[k-1];
    }
};