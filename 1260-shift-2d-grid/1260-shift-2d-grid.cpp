class Solution {
public:
    int r;int c;
    void Shift(vector<vector<int>>&grid){
        vector<int>last(r);
        for(int i=0;i<r;i++){
            last[i]=grid[i][c-1];
        }
        int l=grid[r-1][c-1];
        for(int i=0;i<r;i++){
            for(int j=c-1;j>0;j--){
                grid[i][j]=grid[i][j-1];
            }
        }
        
        for(int i=1;i<r;i++){
            grid[i][0]=last[i-1];
        }
        grid[0][0]=l;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        r=grid.size();
        c=grid[0].size();
        while(k){
            Shift(grid);k--;
        }
        return grid;
    }
};