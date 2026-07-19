class Solution {
public:
    int F(long long index,long long sum,vector<int>&coins,int amount,vector<vector<long long>>&dp){
        if(index>=coins.size()||sum>amount)return 1e9;
        if(sum==amount)return dp[index][sum]=0;
        if(dp[index][sum]!=-1)return dp[index][sum];
        int take=F(index+1,sum,coins,amount,dp);
        int NotTake=1+F(index,sum+coins[index],coins,amount,dp);
        return dp[index][sum]=min(take,NotTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int d=1e9;
        vector<vector<long long>>dp(coins.size()+1,vector<long long>(amount+1,-1));
        d= F(0,0,coins,amount,dp);
        if(d==1e9)return -1;return d;
    }
};