class Solution {
  public:
  int Frog(int index,vector<int>&height, vector<int>&dp){
      
      if(index==height.size()-1){
          return dp[index]=0;
      }
      if(dp[index]!=-1)return dp[index];
      int Take=1e9;int NotTake=1e9;
      if(index+1<height.size()){
         Take=abs(height[index]-height[index+1])+Frog(index+1,height,dp);
      }
      if(index+2<height.size()){
         NotTake=abs(height[index]-height[index+2])+Frog(index+2,height,dp);
      }
      return dp[index]=min(Take,NotTake);
  }
    int minCost(vector<int>& height) {
        int sum=0;
        vector<int>dp(height.size()+1,-1);
         Frog(0,height,dp);
         return dp[0];
         
    }
};
