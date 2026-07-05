class Solution {
public:
    int  Function(int index1,int index2,string &text1, string &text2, vector<vector<int>>&dp){
        if(index1>=text1.size()||index2>=text2.size()){
            return 0;
        }
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(text1[index1]==text2[index2]){
            return dp[index1][index2]=1+Function(index1+1,index2+1,text1,text2,dp);
        }
        int Take=Function(index1+1,index2,text1,text2,dp);
        int NotTake=Function(index1,index2+1,text1,text2,dp);
        return dp[index1][index2]=max(Take,NotTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
       return Function(0,0,text1,text2,dp);
    }
};