class Solution {
public:
    int House2(int index,int end,vector<int>& nums,vector<int>&dp){
        if(index>=end)return 0;
       if(dp[index]!=-1)return dp[index];
        int Take=nums[index]+House2(index+2,end,nums,dp);
        int NotTake=House2(index+1,end,nums,dp);
        return dp[index]=max(Take,NotTake);

    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size()+1,-1);
        if(nums.size()==1)return nums[0];
       int l= House2(0,nums.size()-1,nums,dp1);
       vector<int>dp2(nums.size()+1,-1);
       int r=House2(1,nums.size(),nums,dp2);
       return max(l,r);
    }
};