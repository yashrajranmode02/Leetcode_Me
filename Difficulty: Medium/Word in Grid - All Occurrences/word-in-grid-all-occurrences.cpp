class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int, int>> starts;

        // Step 1: Store all possible starting positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    starts.push_back({i, j});
                }
            }
        }

        vector<vector<int>> ans;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Step 2: Iterate over all starting positions
        for (auto [r, c] : starts) {

            // Step 3: Try all 8 directions
            for (int d = 0; d < 8; d++) {

                int nr = r;
                int nc = c;
                int k = 0;

                while (k < word.size()) {

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        break;

                    if (mat[nr][nc] != word[k])
                        break;

                    nr += dr[d];
                    nc += dc[d];
                    k++;
                }

                // Complete word found
                if (k == word.size()) {
                    ans.push_back({r, c});
                    break;
                }
            }
        }

        // Step 4: Lexicographical order
        sort(ans.begin(), ans.end());

        return ans;
    }
};