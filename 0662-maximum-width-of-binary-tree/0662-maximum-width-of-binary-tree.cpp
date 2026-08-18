class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue < pair<TreeNode*, int>> q; 
        q.push({root, 0}); long long ans=0;
        while (!q.empty()) {
            int n = q.size();int first=q.front().second;
            long long last=0;
            while (n) {
                auto it = q.front();
                q.pop();
                 last=it.second;
                TreeNode* temp=it.first;
                if(n==1)last=it.second;
                if(temp->left){
                    q.push({temp->left,1LL*it.second*2+1});
                }
                if(temp->right){
                    q.push({temp->right,1LL*it.second*2+2});
                }
                n--;
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};