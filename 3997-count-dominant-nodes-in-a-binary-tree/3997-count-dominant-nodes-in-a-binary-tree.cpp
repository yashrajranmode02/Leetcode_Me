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
    int count = 0;
    int f(TreeNode* root) {
        if (!root)
            return 0;
        if (root && !root->left && !root->right) {
            cout << root->val;
            count += 1;
            return root->val;
        }
        int l = f(root->left);
        int r = f(root->right);
        if (root->val >= max(l, r)) {
            cout << root->val;
            count++;
        }
        return max(root->val, max(l, r));
    }
    int countDominantNodes(TreeNode* root) {   f(root);return count; }
}; 