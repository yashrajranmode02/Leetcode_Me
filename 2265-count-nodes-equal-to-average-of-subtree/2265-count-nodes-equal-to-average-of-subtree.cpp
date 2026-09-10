/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
   
    int c = 0;
    int f(TreeNode* root){
        if(!root)return 0;
       int l= f(root->left);
       int r= f(root->right);
        return 1+l+r;
    }
     int d(TreeNode* root, int a) {
        if (!root)
            return 0; 
       int l= d(root->left,a);
       int r= d(root->right,a);
       
        int x=(f(root));
         cout<<root->val<<" "<<l<<" "<<r<<" "<<x<<endl;
       if(root->val==floor(((root->val+l+r)/x))){ 
        c++;
        }
       return root->val+l+r;
    }
    
    int averageOfSubtree(TreeNode* root) {
        int a = 0; int b = 0;
        d(root,a); 
        return c;
    }
};