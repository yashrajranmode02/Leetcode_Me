class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>freq;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            int l=nums[i];
            int s=INT_MAX;int e=INT_MIN; 
            while(l){
                s=min(s,l%10);
                e=max(e,l%10);l/=10;
            }
            mpp[nums[i]]=e-s;maxi=max(maxi,e-s);
        }
        int count=0;
        for(auto&it:mpp){
            if(maxi==it.second){count+=freq[it.first]*it.first;}
        }
        return count;
    }
};