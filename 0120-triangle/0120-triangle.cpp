class Solution {
public:

    int solve(vector<vector<int>>& triangle, int r , int c,vector<vector<int>>& dp){
        if(r==triangle.size()  ) return dp[r][c]=0;
        if(dp[r][c]!=1e9) return dp[r][c];
        int a=triangle[r][c]+solve(triangle,r+1,c,dp);
        int b=triangle[r][c]+solve(triangle,r+1,c+1,dp);
        return dp[r][c]=min(a,b);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(triangle[n-1].size()+1,1e9));
        return solve(triangle,0,0,dp);
    }
};