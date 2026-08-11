class Solution {
public:
int F(int index,int n,vector<int>& costs,vector<int>&dp){
    if(index>=costs.size())return dp[index]=0;
    // if(index>costs.size())return 1e9;
    if(dp[index]!=-1)return dp[index];
    int a=1e9;
    if(index+1<=n)a=costs[index]+1+F(index+1,n,costs,dp);
    int b=1e9;
    if(index+2<=n)b=costs[index+1]+4+F(index+2,n,costs,dp);
    int c=1e9;
    if(index+3<=n)c=costs[index+2]+9+F(index+3,n,costs,dp);
    return dp[index]=min(a,min(b,c));
}
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(costs.size()+1,-1);
      return  F(0,n,costs,dp);
    }
};