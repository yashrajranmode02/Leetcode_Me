class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        long long min1 = LLONG_MAX;
        long long min2 = LLONG_MAX;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] > max3)
                max3 = nums[i];

            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        cout << max1 << max2 << max3 << " ";
        cout << min1 << min2;
        return max(1LL * max1 * max2 * max3, 1LL * max1 * min1 * min2);
    }
};