class Solution {
public:
    int r,c;
    int Unique_Path(vector<vector<int>>& obstacleGrid,int index1,int index2,vector<vector<int>>&dp){
        
       
        if(index1==r||index2==c)return dp[index1][index2]=0;
        if(obstacleGrid[index1][index2]==1)return 0;
         if(index1==r-1&&index2==c-1)return dp[index1][index2]=1;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        return dp[index1][index2]=Unique_Path(obstacleGrid,index1+1,index2,dp)+Unique_Path(obstacleGrid,index1,index2+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        r=obstacleGrid.size();
        c=obstacleGrid[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,-1));
         Unique_Path(obstacleGrid,0,0,dp);
         return dp[0][0]==-1?0:dp[0][0];
    }
};