class Solution {
public:
    int trailingZeroes(int n) {
        int d=-1;int fivisor=5;int c=0;
        while(d!=0){
            d=(n/fivisor);c+=d;fivisor*=5;
        }
        return c;
    }
};