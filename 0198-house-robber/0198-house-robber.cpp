class Solution {
public: 
    int rob(vector<int>& nums) {
        int sum=0;vector<int>dp(nums.size());int n=nums.size();
        dp[nums.size()-1]=nums[nums.size()-1];if(n==1)return nums[nums.size()-1];
        dp[nums.size()-2]=max(nums[n-1], nums[n-2]); if(n==2)return max(nums[nums.size()-1],nums[nums.size()-2]);
        for(int i=n-3;i>=0;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};