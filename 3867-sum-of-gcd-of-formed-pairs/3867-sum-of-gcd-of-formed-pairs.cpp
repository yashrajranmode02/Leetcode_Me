class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxi(n,-1);
        vector<int>prefixGcd(n,0);int c=-1;
        for(int i=0;i<n;i++){
            c=max(c,nums[i]);
            maxi[i]=max(maxi[i],c);
        }
       
        for(int i=0;i<nums.size();i++){
            prefixGcd[i]=gcd(nums[i], maxi[i]);
        }
        long long ans=0;
       
        sort(prefixGcd.begin(),prefixGcd.end());
        int start=0;
        int end=prefixGcd.size()-1;
        
        while(start<end){
            ans+=gcd(prefixGcd[start],prefixGcd[end]);
            start++;end--;
        }
        return ans;
    }
};