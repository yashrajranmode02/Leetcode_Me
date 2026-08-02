class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ans=max(ans,(1LL*nums[i]*nums[j])/(1LL*gcd(nums[i],nums[j])*gcd(nums[i],nums[j])));
            }
        }
        return ans;
    }
};