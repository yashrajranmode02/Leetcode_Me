class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        // Base case
        if (i == s1.size() || j == s2.size()) return 0;

        // Memo check
        if (dp[i][j] != -1) return dp[i][j];

        // Match case
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1, dp);
        }

        // Not match
        return dp[i][j] = max(
            solve(s1, s2, i + 1, j, dp),
            solve(s1, s2, i, j + 1, dp)
        );
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int lcs = solve(word1, word2, 0, 0, dp);

        return (n - lcs) + (m - lcs);
    }
};