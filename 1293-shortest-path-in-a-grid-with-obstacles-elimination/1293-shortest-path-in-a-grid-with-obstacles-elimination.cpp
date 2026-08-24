class Solution {
public:
    int r;
    int c;
    int row_array[4] = {-1, 1, 0, 0};
    int col_array[4] = {0, 0, -1, 1};
    bool check(int m, int n) { return m >= 0 && m < r && n >= 0 && n < c; }
    int shortestPath(vector<vector<int>>& grid, int obs) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<pair<int, int>, int>> q; 
        vector<vector<vector<bool>>> v(r+1,vector<vector<bool>>(c+1,vector<bool>(obs+1,0)));

        q.push({{0, 0}, 0});
        v[0][0][0]=1;
        int count = 0;
        bool yes = 0;
        int ans = INT_MAX;
        while (!q.empty()) {
            int n = q.size();
            while (n) {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int current_rem = q.front().second; 
                q.pop();
                if (row == r - 1 && col == c - 1) {
                    if (current_rem <= obs) {
                        ans = min(ans, count);
                        yes = 1;
                    }
                }

                for (int k = 0; k < 4; k++) {
                    if (check(row + row_array[k], col + col_array[k]) &&
                        current_rem <= obs &&
                        v[row + row_array[k]][col + col_array[k]][current_rem] != 1) {
                        if (grid[row + row_array[k]][col + col_array[k]] == 1) {
                            q.push({{row + row_array[k], col + col_array[k]},
                                    current_rem + 1});
                        } else {
                            q.push({{row + row_array[k], col + col_array[k]},
                                    current_rem});
                        }
                       v [row + row_array[k]] [col + col_array[k]] [current_rem] = 1;
                    }
                }
                n--;
            }
            count++;
        }
        if (!yes)
            return -1;
        return ans;
    }
};