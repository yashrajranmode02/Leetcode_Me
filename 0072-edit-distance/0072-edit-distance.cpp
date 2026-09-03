class Solution {
public:
    int Edit_Distance(int index1,int index2 ,string &word1,string &word2,vector<vector<int>>&dp){
            if(index2==-1){
                return index1+1;
            }
            if(index1==-1){
                return index2+1;
            }
            if(dp[index1][index2]!=-1)return dp[index1][index2];
            if(word1[index1]==word2[index2]){
              return Edit_Distance(index1-1,index2-1,word1,word2,dp);
            }
          return dp[index1][index2]=1+min(min(
                           Edit_Distance(index1,index2-1,word1,word2,dp),
                           Edit_Distance(index1-1,index2,word1,word2,dp)),
                           Edit_Distance(index1-1,index2-1,word1,word2,dp));
               
    }
    int minDistance(string word1, string word2) {
        int n=word1.size()-1;
        int m=word2.size()-1;
        vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
     return   Edit_Distance(n,m,word1,word2,dp);
    }
};