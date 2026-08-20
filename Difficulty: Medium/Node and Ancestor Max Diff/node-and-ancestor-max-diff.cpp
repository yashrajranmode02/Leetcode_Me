/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int F(Node* &root,int &ans){
        if(!root)return (1e5);
        int lefty=F(root->left,ans);
        int righty=F(root->right,ans);
        ans=max(ans,max(root->data-lefty,root->data-righty));
        return min(root->data,min(lefty,righty));
    }
    int maxDiff(Node* root) {
        // code here
        int ans=INT_MIN;
        F(root,ans);
        // if(ans==0)return -1;
        return ans;
    }
};