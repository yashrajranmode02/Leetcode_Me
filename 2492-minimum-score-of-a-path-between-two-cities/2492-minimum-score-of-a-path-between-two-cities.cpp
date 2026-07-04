class Solution {
public:
    bool Function(int n ,int index, vector<vector<pair<int, int>>>& adjacency_list,
                  queue<pair<int, int>>& q, vector<int>& visited, int& mini) {
bool yes=0;
        q.push({index, 0});
        while (!q.empty()) {
            int node = q.front().first;
            if(node==n)yes=1;
            visited[node] = 1;
            int weight = q.front().second;
            q.pop();
            for (int i = 0; i < adjacency_list[node].size(); i++) {
                int neighbour = adjacency_list[node][i].first;
                int w = adjacency_list[node][i].second;
                if (visited[neighbour] == 0) {
                    
                    q.push({neighbour, w});
                    mini = min(mini, w);
                }
            }
        }
        return yes;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjacency_list(n);
        for (int i = 0; i < roads.size(); i++) {
            adjacency_list[roads[i][0] - 1].push_back(
                {roads[i][1] - 1, roads[i][2] - 1});
            adjacency_list[roads[i][01] - 1].push_back(
                {roads[i][0] - 1, roads[i][2] - 1});
        }
        queue<pair<int, int>> q;
        vector<int> visited(n);
        int mini = INT_MAX;
        // for (int i = 0; i < n; i++) {
            // if (visited[i] == 0)
                if(Function(n,0, adjacency_list, q, visited, mini))return mini;
        // }
        return mini + 1;
    }
};