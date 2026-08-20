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
    void inorder(TreeNode* root, int &ans, int maxval, int minval){
        if(!root) return;

        maxval = max(maxval, root->val);
        minval = min(minval, root->val);
        ans = max(ans, maxval - minval);
        inorder(root->left, ans, maxval, minval);
        inorder(root->right, ans, maxval, minval);
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans = 0, maxval = INT_MIN, minval = INT_MAX;
        inorder(root, ans, maxval, minval);
        return ans;
    }
};