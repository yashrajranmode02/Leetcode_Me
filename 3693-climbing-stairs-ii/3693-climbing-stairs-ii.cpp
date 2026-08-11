class Solution {
public:
    int Climbing_Stair(vector<int>&dp,int index,vector<int>&costs){
        if(index==costs.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int a=1e9;
        if(index+1<=costs.size())
        a=costs[index]+(1)+Climbing_Stair(dp,index+1,costs);
        int b=1e9;
        if(index+2<=costs.size())
        b=costs[index+2-1]+(4)+Climbing_Stair(dp,index+2,costs);
        int c=1e9;
        if(index+3<=costs.size())
        c=costs[index+3-1]+(9)+Climbing_Stair(dp,index+3,costs);
        return dp[index]=min(a,min(b,c));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n,-1);
       return Climbing_Stair(dp,0,costs);
    }
};