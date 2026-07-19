class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1)return s;
        if(n==2)return (s)+m;
        // 3, 8, 7, 12, 11, 16, 15, 20
        // n=1 ->s
        // n=2 ->s+m
        // n=3 ->(s+m-1)
        // n=4 ->s+2*m-1 
        // n=5 ->s+2*m-2
        // n=6 ->s+3*m-2
        // n=7 ->s+2*m-3 
        // n=8 ->s+3*m-2
        // n=9 ->s+2*m-3
        // n=10->s
        if(n%2==0){
            return s+1LL*(n/2)*m-(n/2-1);
        }
        return s +1LL*(n/2)*m -(n/2-1);
    }
};