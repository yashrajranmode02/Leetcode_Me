class Solution {
public:
    int Function(int index1,int index2,string &s,string &t,vector<vector<int>>&dp){
        if(index2==t.size()){
            return dp[index1][index2]=1;
        }
        if(index1==s.size()&&index2<t.size())return dp[index1][index2]=0;
        int take=0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(s[index1]==t[index2]){
          take= Function(index1+1,index2+1,s,t,dp);
        }
        int NotTake=Function(index1+1,index2,s,t,dp);
        return dp[index1][index2]=take+NotTake;

    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
         Function(0,0,s,t,dp);
         return dp[0][0];
    }
};