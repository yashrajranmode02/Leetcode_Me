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
class BSTIterator {
public:
    vector<TreeNode*> ans;
    int index = 0;
    void F(TreeNode* root, vector<TreeNode*>& ans) {
        if (!root)
            return;
        F(root->left, ans);
        ans.push_back(root);
        F(root->right, ans);
    }
    BSTIterator(TreeNode* root) {

        ans.push_back(new TreeNode(-1));
        F(root, ans);
    }

    int next() {
        if (index == ans.size())
            return -1;

        return ans[++index]->val;
    }

    bool hasNext() {
        
        return index+1<ans.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */