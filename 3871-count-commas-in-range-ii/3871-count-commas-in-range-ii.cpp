class Solution {
public:
    long long countCommas(long long n) {
        
        if(n<=999)return 0;
        if(1000<=n&&n<=1e6-1)return n-999;
        if(1e6<=n&&n<=1e9-1)return 2*(n-(1e6-1))+(1e6-1-999);
        if(1e9<=n&&n<=1e12-1)return 3*(n-(1e9-1))+ 2*((1e9-1)-(1e6-1))+(1e6-1-999);
        if(1e12<=n&&n<=1e15-1)return 4*(n-(1e12-1))+3*((1e12-1)-(1e9-1))+ 2*((1e9-1)-(1e6-1))+(1e6-1-999);
       
        return 1+4*(n-(1e12-1))+3*((1e12-1)-(1e9-1))+ 2*((1e9-1)-(1e6-1))+(1e6-1-999);
    }
};