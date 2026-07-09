class Solution {
public:
    TreeNode* F(int s, int end, TreeNode*& root, vector<int>& nums) {
        if (s > end)
            return NULL;
        int mid = s + (end - s) / 2;
        TreeNode* temp = NULL;
        if (mid < nums.size()) {
            temp = new TreeNode(nums[mid]);
            temp->left = F(s, mid - 1, root, nums);
            temp->right = F(mid + 1, end, root, nums);
        }

        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        return F(0, nums.size(), root, nums);
    }
};