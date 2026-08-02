class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            int o=0;int e=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0)e++;
                else o++;

                if(o>0&&(b*e<=a*o))c++;
            }
        }
        return c;
    }
};