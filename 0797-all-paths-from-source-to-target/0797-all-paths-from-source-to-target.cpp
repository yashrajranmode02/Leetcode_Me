class Solution {
public: vector<int>temp;
    void DFS(int node, vector<vector<int>>& graph, vector<vector<int>>& ans,
             vector<int> visited) {
                if(node==graph.size()-1){
                    temp.push_back(node);
                    ans.push_back(temp);return ;
                }
                visited[node]=1;
               
                temp.push_back(node);
                for(int i=0;i<graph[node].size();i++){
                    if(!visited[graph[node][i]]){
                        DFS(graph[node][i],graph,ans,visited);
                          temp.pop_back();
                    }
                }
                visited[node]=0;
              
             }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> visited(graph.size());
        DFS(0, graph, ans, visited);
        return ans;
    }
};