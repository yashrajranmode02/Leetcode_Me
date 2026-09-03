class Solution {
public:
    int f(int s,int n, vector<int>&dp){ 
        if(s==n)return 1;
        if(dp[s]!=-1)return dp[s];
        int take=0;
        if(s+1<=n)take=f(s+1,n,dp);
        int NotTake=0;
        if(s+2<=n)NotTake=f(s+2,n,dp);
        return dp[s]=take+NotTake; 
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
       return f(0,n,dp);
    }
};