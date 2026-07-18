class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int n = nums.size();
        bool p = 0;
        for (int i = 0; i < nums.size(); i++) {
            xr = xr ^ nums[i];
            if(nums[i]!=0)p=1;
        }
        if(!p&&!xr)return 0;
        if (xr == 0)
            return n - 1;
        if (xr == n)
            return xr;
        return n;
    }
};