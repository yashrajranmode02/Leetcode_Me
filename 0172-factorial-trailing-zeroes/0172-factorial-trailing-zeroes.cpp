class Solution {
public:
    int trailingZeroes(int n) {
        int c = 0;
        int d = -1;
        int fivisor = 5;
        while (d != 0) {
            d = n / fivisor;
            c+=d;fivisor*=5;
        }
        return c;
    }
};