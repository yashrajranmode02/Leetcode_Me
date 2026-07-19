class Solution {
public:
    bool Wild_Card(string& s, string& p, int first, int second,
                   vector<vector<int>>& dp) {
        if (first == s.size() && second == p.size()) {
            return dp[first][second] = true;
        }
        if (first != s.size() && second == p.size())
            return dp[first][second] = false;
        if (second != p.size() && first == s.size()) {
            bool f = 1;
            for (int i = second; i < p.size(); i++) {
                if (p[i] != '*') {
                    f = 0;
                }
            }
            return dp[first][second] = f;
        }
        if (dp[first][second] != -1)
            return dp[first][second];
        if (s[first] == p[second] || p[second] == '?')
            return Wild_Card(s, p, first + 1, second + 1, dp);
        if (p[second] == '*') {
            return dp[first][second] = Wild_Card(s, p, first + 1, second, dp) ||
                                       Wild_Card(s, p, first, second + 1, dp);
        }
        return dp[first][second] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return Wild_Card(s, p, 0, 0, dp);
    }
};