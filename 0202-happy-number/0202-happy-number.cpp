class Solution {
public:
    bool isHappy(int n) {
        if (n == 1)
            return 1; 

        unordered_map<int,int>mpp;
        mpp[n]=1;
        while (n > 1) {
            int newy = n;
            int ans = 0;
            
            while (n) { 
                ans += (n % 10) * (n % 10);
                n /= 10; 
            }
            cout<<ans<<" " ;
            if(ans==1)return true;
            if(mpp.find(ans)!=mpp.end())return 0;

            mpp[ans]=1;
            if (newy == ans)
                return 0;
            n = ans;
        }
        return true;
    }
};