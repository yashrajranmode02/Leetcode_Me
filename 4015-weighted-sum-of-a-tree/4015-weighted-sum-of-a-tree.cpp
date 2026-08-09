class Solution {
public:
    void BFS(vector<int>& depth,
             vector<vector<pair<int, int>>>& adjacency_list) {
        queue<int> q;
        long long level = 1;
        q.push(0);
        while (!q.empty()) {
            int n = q.size();
            while (n) {
                int node = q.front();
                q.pop();
                depth[node] = level;
                for(int i=0;i<adjacency_list[node].size();i++){
                    q.push(adjacency_list[node][i].first);
                }
                 n--;
            }
           
            level++;
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<vector<pair<int, int>>> adjacency_list(nums.size(),
                                                      vector<pair<int, int>>());
        for (int i = 1; i < nums.size(); i++) {
            adjacency_list[parent[i]].push_back({i, nums[i]});
        }
        // for(int i=0;i<adjacency_list.size();i++){
        //     for(int j=0;j<adjacency_list[i].size();j++){
        //         cout<<j<<"->"<<adjacency_list[i][j].first<<"->"<<adjacency_list[i][j].second;cout<<endl;
        //     }
        // }
        vector<int> depth(nums.size(), 1);
        BFS(depth, adjacency_list);

        int h = depth[depth.size() - 1];
        for(int i=0;i<depth.size();i++){
            cout<<depth[i]<<" ";
            h=max(h,depth[i]);
        }
        long long ans = 0;
        for (int i = 0; i < depth.size(); i++) {
            ans += (1LL * nums[i] * (h - depth[i] + 1));
        }

        return ans;
    }
};