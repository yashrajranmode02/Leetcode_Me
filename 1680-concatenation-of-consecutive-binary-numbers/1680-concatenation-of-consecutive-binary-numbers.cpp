class Solution {
public:
const long long mod = 1000000007;
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int f=floor(log(i)/log(2))+1;
            ans=((ans<<f)|i)%mod;
        }
        
        return (int)ans;
    }
};