class Solution {
public:
    int row_array[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
    int col_array[8] = {0, 0, -1, 1, 1, 1, -1, -1};
    int r = 0;
    int c = 0;
    bool check(int m, int n) { return m >= 0 && m < r && n >= 0 && n < c; }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        r = grid.size();
        c = grid[0].size();
        queue<pair<int, int>> q;
        q.push({0, 0});
        int count = 0;  int ans=INT_MAX;
        while (!q.empty()) {
            int n = q.size();
            count++;
          
            cout << q.front().first << "->" << q.front().second << endl;
            while (n) {
                int r1 = q.front().first;
                int c1 = q.front().second;
                q.pop();
                if (r1 == r - 1 && c1 == c - 1)
                    {
                        ans=min(ans,count);
                    }
                grid[r1][c1] = 1;
                for (int k = 0; k < 8; k++) {
                    if (check(r1 + row_array[k], c1 + col_array[k]) &&
                        grid[r1 + row_array[k]][c1 + col_array[k]] == 0) {
                        q.push({r1 + row_array[k], c1 + col_array[k]});
                        grid[r1 + row_array[k]][c1 + col_array[k]] = 1;
                    }
                }
                n--;
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};