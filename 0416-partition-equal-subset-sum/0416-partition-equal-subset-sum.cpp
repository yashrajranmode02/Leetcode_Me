class Solution {
public:
bool F(vector<int>&nums,int index,int sum,int target,vector<vector<int>>&dp){
    if(sum==target)return true;
    if(index==nums.size()){return 0;}
    if(dp[index][sum]!=-1)return dp[index][sum];

    return dp[index][sum]=F(nums,index+1,sum+nums[index],target,dp)||F(nums,index+1,sum,target,dp);
}
    bool canPartition(vector<int>& nums) {
        int sum=0;for(auto it:nums)sum+=it;
        if(sum%2!=0)return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return F(nums,0,0,sum/2,dp);
    }
};