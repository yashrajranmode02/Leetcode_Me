class Solution {
public:
    bool F(vector<int>& arr, int i, vector<bool>& Visited) {
        if (i >= arr.size()) {
            return 0;
        }
        if(arr[i]==0)return 1;
        bool t=0;bool q=0;
        if (i+arr[i]<Visited.size()&&!Visited[i + arr[i]]) {
            Visited[i + arr[i]] = 1;
           t= F(arr, i + arr[i], Visited);
            Visited[i + arr[i]] = 0;
        }
        if (i-arr[i]>=0&&!Visited[i - arr[i]]) {
            Visited[i - arr[i]] = 1;
           q= F(arr, i - arr[i], Visited);
            Visited[i - arr[i]] = 0;
        }
        return t||q; 
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> Visited(arr.size(), 0);
        return F(arr, start, Visited);
    }
};