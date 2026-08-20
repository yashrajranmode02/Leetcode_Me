class Solution {
public:
    bool check(int i, vector<vector<char>>& board, int row, int col) {
        char index = i+'0';
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == index)
                return false;
            if (board[row][i] == index)
                return false;
        }
        if (row >= 0 && row <= 2) {
            if (col >= 0 && col <= 2) {
                for (int i = 0; i <= 2; i++) {
                    for (int j = 0; j <= 2; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
            if (col >= 3 && col <= 5) {
                for (int i = 0; i <= 2; i++) {
                    for (int j = 3; j <= 5; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
            if (col >= 6 && col <= 8) {
                for (int i = 0; i <= 2; i++) {
                    for (int j = 6; j <= 8; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
        }

        if (row >= 3 && row <= 5) {
            if (col >= 0 && col <= 2) {
                for (int i = 3; i <= 5; i++) {
                    for (int j = 0; j <= 2; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
            if (col >= 3 && col <= 5) {
                for (int i = 3; i <= 5; i++) {
                    for (int j = 3; j <= 5; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
            if (col >= 6 && col <= 8) {
                for (int i = 3; i <= 5; i++) {
                    for (int j = 6; j <= 8; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
        }
        if (row >= 6 && row <= 8) {
            if (col >= 0 && col <= 2) {
                for (int i = 6; i <= 8; i++) {
                    for (int j = 0; j <= 2; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
            if (col >= 3 && col <= 5) {
                for (int i = 6; i <= 8; i++) {
                    for (int j = 3; j <= 5; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
            if (col >= 6 && col <= 8) {
                for (int i = 6; i <= 8; i++) {
                    for (int j = 6; j <= 8; j++) {
                        if (board[i][j] == index)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    bool Solve(int i, vector<pair<int, int>>& mpp,
               vector<vector<char>>& board) {
        if (i == mpp.size())
            return 1;
        int row = mpp[i].first;
        int col = mpp[i].second;
        for (int index = 1; index <= 9; index++) {

            if (check(index, board, row, col)) {
                board[row][col] = index+'0';
                if (Solve(i + 1, mpp, board))
                    return true;

                board[row][col] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> mpp;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    mpp.push_back({i, j});
                }
            }
        }
      
        Solve(0, mpp, board);
    }
};