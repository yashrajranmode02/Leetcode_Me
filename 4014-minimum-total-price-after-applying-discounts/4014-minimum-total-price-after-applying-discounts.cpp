class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        int p2 = discounts.size() - 1;
        int i = prices.size() - 1;
        double ans=0;
        for (i = prices.size() - 1; i >= 0; i--) {
            if (p2 < 0){
                break;
            }
            ans+=(prices[i]*(100-discounts[p2])/100.0);
            p2--;
        }
        while (i>=0) {
            ans += prices[i];
            i--;
        }
        return ans;
    }
};