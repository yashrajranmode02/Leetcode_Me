class Solution {
public:
int Change(int index,int sum,int amount,vector<int>&coins,vector<vector<int>>&dp){
    if(sum==amount)return 1;
    if(index>=coins.size()||sum>amount)return 0;
    if(dp[index][sum]!=-1)return dp[index][sum];
    int Take=0;int NotTake=0; 
      Take=Change(index,sum+coins[index],amount,coins,dp);
      NotTake=Change(index+1,sum,amount,coins,dp);
    return dp[index][sum]=Take+NotTake;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
       return Change(0,0,amount,coins,dp);
    }
};