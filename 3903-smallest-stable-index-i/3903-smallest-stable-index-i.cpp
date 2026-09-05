class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mini(n,0);
        vector<int>maxi(n,0);int m=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>m){
                m=nums[i];
            }
           
                maxi[i]=m;
            
        }
        m=INT_MAX;
        for(int j=n-1;j>=0;j--){
            if(nums[j]<m){
                m=nums[j];
            }
                mini[j]=m;
            
        }
        
        for(int i=0;i<nums.size();i++){
            if(maxi[i]-mini[i]<=k)return i;
        }
        return -1;
    }
};