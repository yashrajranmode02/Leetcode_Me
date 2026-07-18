class Solution {
public:
    int minimumSum(int n, int k) {
        // if(n<k)return (n*(n+1))/2;
        long long sum = 0;
        int i = 1;
        while (n&& i <= k / 2) {
            sum += i;
            i++;
            n--;
        }
        if(n==0)return sum;
        cout << n;
        i = k;
        // cout << n;
        while (n) {
            sum += i;
            i++;
            n--;
        }
        // sum += i;
        // cout << sum;
        return (int)sum;
    }
};