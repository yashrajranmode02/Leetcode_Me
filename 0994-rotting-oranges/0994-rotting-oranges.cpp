class Solution {
public:
    int m,n;
    vector<int>row_array={-1,1,0,0};
    vector<int>col_array={0,0,1,-1};
    bool check(int i,int j){
        return i>=0&&i<m&&j>=0&&j<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int min=0;
         m=grid.size();int s=0;
         n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    s++;
                }
            }
        }
        int g=0;
        while(!q.empty()){
            int n=q.size();bool change=0;
            while(n--){
            int index1=q.front().first;
            int index2=q.front().second;q.pop();
            grid[index1][index2]=-1;
            for(int k=0;k<4;k++){
                int p=index1+row_array[k];int q2=index2+col_array[k];
                if(check(p,q2)&&grid[p][q2]==1){
                    grid[p][q2]=2;
                    q.push(make_pair(p,q2));g++;change=1;
                }
             }
          }
          if(change)
          min++; 
        } 
        if(s!=g)return -1;
        return min;
    }
};