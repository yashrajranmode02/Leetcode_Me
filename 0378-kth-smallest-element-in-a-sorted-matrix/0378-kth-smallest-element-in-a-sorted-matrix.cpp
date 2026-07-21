class Solution {
public:
    int r, c;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        r = matrix.size();
        c = matrix[0].size();
        // k = r % k;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for (int i = 0; i < r; i++) {
            pq.push({matrix[i][0],{i,0}});
        }
        while (!pq.empty()&&k>1) {
            int node=pq.top().first;
            cout<<node<<" ";
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col+1<c)pq.push({matrix[row][col+1],{row,col+1}});
            k--;
        }
        return pq.top().first;
    }
};