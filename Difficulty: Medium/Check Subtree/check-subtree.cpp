class Solution {
  public:
  void F(Node* root,string &s){
      if(!root)return ;
      s+=root->data+'0';
      F(root->left,s);
      F(root->right,s);
      
  }
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        if(root1==NULL)return 0;
        if(root1==root2)return true;string a="";string b="";
        F(root1,a);
        F(root2,b);
        int g=a.find(b);
        if(g==-1)return 0;
        return 1;
    }
};