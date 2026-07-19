class Solution {
public:
    int row_array[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int col_array[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    bool check(int m, int n) { return m >= 0 && m < 8 && n >= 0 && n < 8; }
    bool canReach(vector<int>& start, vector<int>& target) {
        queue<pair<int, int>> q;
        int count = 0;
        q.push({start[0], start[1]});
        vector<vector<bool>> visited(8, vector<bool>(8, 0));
        while (!q.empty()) {
            count++;
            int n = q.size();
            while (n) {
                int n1 = q.front().first;
                int n2 = q.front().second;
                visited[n1][n2] = 1;
                q.pop();
                if (n1 == target[0] && n2 == target[1] && count % 2 != 0)
                    return 1;
                for (int k = 0; k < 8; k++) {
                    if (check(n1 + row_array[k], n2 + col_array[k]) &&
                        !visited[n1 + row_array[k]][n2 + col_array[k]]) {
                        q.push({n1 + row_array[k], n2 + col_array[k]});
                        visited[n1 + row_array[k]][n2 + col_array[k]] = 1;
                    }
                }
                n--;
            }
        }
        return 0;
    }
};