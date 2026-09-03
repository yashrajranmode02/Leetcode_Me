class Solution {
public:
int RCB(int index,vector<int>& nums,vector<int>&dp){
    if(index>=nums.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    return dp[index]=max(nums[index]+RCB(index+2,nums,dp),RCB(index+1,nums,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return RCB(0,nums,dp);
    }
};