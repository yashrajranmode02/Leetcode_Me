class Solution {
public:
    int V(int index,int n,vector<int>&dp){ 
        if(index>n)return dp[index]=0;
        if(index==n)return dp[index]=1;
        if(dp[index]!=-1)return dp[index];
         return dp[index]=(V(index+1,n,dp)+V(index+2,n,dp ));
    }
    int climbStairs(int n) {
        vector<int>dp(n+2,-1);
         V(0,n,dp);
         return dp[0];
    }
};