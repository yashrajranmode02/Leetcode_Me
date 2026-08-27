class Solution {
  public:
    int minOps(vector<int>& arr, int k) {
        int ans = 0;
        for (int x : arr) {
            if (x > k)
                ans += (x - 1) / k;
        }
        return ans;
    }
};