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
    void F(TreeNode* root) {
        if (!root)
            return; 
        
        if (root->left) {

            TreeNode* head = root->left;
            root->left = NULL;
            TreeNode* temp = head;
            while (temp && temp->right) {
                temp = temp->right;
            }
            TreeNode* p=root->right;
            root->right=head;
            temp->right=p;
        }   
        F(root->left);
         F(root->right); 
    }
    void flatten(TreeNode* root) { F(root); }
};