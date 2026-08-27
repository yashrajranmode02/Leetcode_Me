class Solution {
	public:
	int rec(int i, int prev, int n, vector<vector<int>> & mat,vector<vector<int>>&dp) {
		if (i >= n) {return 0; } 
		if(dp[i][prev]!=-1)return dp[i][prev];
		int first = 1e9;
		if (prev != 0)first = mat[i][0]+rec(i + 1, 0, n, mat,dp);
		int second = 1e9;
		if (prev != 1)second = mat[i][1]+rec(i + 1,  1,n, mat,dp);
		int third = 1e9;
		if (prev != 2)third = mat[i][2]+rec(i + 1,  2,n, mat,dp);
		return dp[i][prev]=min(first, min(second, third));
	}
	int minCost(vector<vector<int>> & mat) {
		int n = mat.size();
		vector<vector<int>>dp(n+1,vector<int>(4,-1));
		return 	rec(0, 3, n, mat,dp);
	}
};
