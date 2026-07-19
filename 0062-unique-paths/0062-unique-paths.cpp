class Solution {
public:
    int Function(int index1,int index2,int m ,int n,vector<vector<int>>&dp){
        if(index1>m||index2>n){return 0;}
        if(index1==m-1&&index2==n-1)return dp[index1][index2]=1;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        return dp[index1][index2]=Function(index1+1,index2,m,n,dp)+Function(index1,index2+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       Function(0,0,m,n,dp);
       return dp[0][0];
    }
};