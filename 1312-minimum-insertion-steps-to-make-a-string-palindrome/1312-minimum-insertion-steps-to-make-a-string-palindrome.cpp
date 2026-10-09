class Solution {
public:
    int recursion(string& text1, string& text2, int first, int second,
                  vector<vector<int>>& dp) {
        if (first == text1.size() || second == text2.size()) {
            return 0;
        }
        if (dp[first][second] != -1)
            return dp[first][second];
        if (text1[first] == text2[second]) {
            return dp[first][second] =
                       1 + recursion(text1, text2, first + 1, second + 1, dp);
        }
        return dp[first][second] =
                   max(recursion(text1, text2, first + 1, second, dp),
                       recursion(text1, text2, first, second + 1, dp));
    }
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int first = 0;
        int second = 0;
        vector<vector<int>> dp(s.length() + 1,
                               vector<int>(s2.length() + 1, -1));
        return s.size() - recursion(s, s2, first, second, dp);
    }
};

;