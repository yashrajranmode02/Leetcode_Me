class Solution {
public:
    int i = 0;
    void Function(TreeNode*& root, vector<int>& d) {
        if (!root)
            return; 
        Function(root->left, d);
        d.push_back(root->val);
        Function(root->right, d);
    }
    void Function2(TreeNode*& root, vector<int>& d) {
        if (!root)
            return; 
        Function2(root->left, d);
        root->val = d[i];
        i++;
        Function2(root->right, d);
    }
    void recoverTree(TreeNode* root) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        vector<int> d;
        Function(root, d);
        // for (int i = 0; i < d.size(); i++) {
        //     cout << d[i] << " "; 
        // }
        cout << endl;
        sort(d.begin(), d.end());
        for (int i = 0; i < d.size(); i++) {
            // cout << d[i] << " ";
        }
        cout << endl;
        Function2(root, d);
        
    }
};