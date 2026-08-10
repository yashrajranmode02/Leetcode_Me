class Solution {
public:
    int ExtraEdges = 0;
    void BFS(int i, vector<vector<int>>& adjacency_list, vector<int>& Visited) {
        queue<int> q;
        q.push(i);
        int edges = 0;
        int Vertex = 0;
        Visited[i] = 1;
        while (!q.empty()) {
            int node = q.front(); 
            Vertex++;
            q.pop(); 
            edges+=adjacency_list[node].size();
            for (int i = 0; i < adjacency_list[node].size(); i++) {
                
                if (!Visited[adjacency_list[node][i]]) {
                    q.push(adjacency_list[node][i]);
                    Visited[adjacency_list[node][i]] = 1;
                }
            }
        } 
        edges/=2;
        if (edges - (Vertex - 1) >= 0) {
            ExtraEdges += (edges - (Vertex - 1));
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjacency_list(n, vector<int>());
        for (int i = 0; i < connections.size(); i++) {
            adjacency_list[connections[i][0]].push_back(connections[i][1]);
            adjacency_list[connections[i][1]].push_back(connections[i][0]);
        }

        int component = 0;
        vector<int> Visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!Visited[i]) {
                component++;
                BFS(i, adjacency_list, Visited);
            }
        }
        // cout<<ExtraEdges;
        if (ExtraEdges >= component - 1)
            return component - 1;
        return -1;
    }
};