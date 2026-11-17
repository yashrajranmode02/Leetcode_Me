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
    int Height(TreeNode* root){
        if(!root)return 0;
        if(!root->left&&!root->right)return 1;
        return 1+max(Height(root->left),Height(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<pair<TreeNode*,int>>q;
      int h=  Height(root);
       vector<int> ans;
        q.push({root,0});
        // ans.push_back(root->val);
        while(!q.empty()){
            int n=q.size();
            while(n){
            TreeNode* temp=q.front().first;
          
            int level=q.front().second;  q.pop();
            if(ans.size()==level){
                ans .push_back(temp->val);
             }
            if(temp->right!=nullptr){
                q.push({temp->right,level+1});
            }
           if(temp->left!=nullptr){
                q.push({temp->left,level+1});
            }
n--;
            } 

        }
         
        return ans ;
    }
};