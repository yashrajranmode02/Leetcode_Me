class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;long long sum=0;
        while(i<nums.size()){
            if(i+1<nums.size())
            sum+=min(nums[i],nums[i+1]);
            i++;i++;
        }
        return (int)sum;
    }
};