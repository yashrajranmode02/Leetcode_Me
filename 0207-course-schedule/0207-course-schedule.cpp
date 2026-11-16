class Solution {
public:
    bool Function(queue<int>& q, vector<int>& inDegree,
                  vector<vector<int>>& adjacency_list) {
        if (q.empty())
            return 0;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (int i = 0; i < adjacency_list[n].size(); i++) {
                inDegree[adjacency_list[n][i]]--;
                if (inDegree[adjacency_list[n][i]] == 0) {
                    q.push(adjacency_list[n][i]);
                }
            }
        }
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] != 0)
                return 0;
        }
        return 1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjacency_list(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adjacency_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                
                q.push(i);
            }
        }
        return Function(q, inDegree, adjacency_list);
    }
};