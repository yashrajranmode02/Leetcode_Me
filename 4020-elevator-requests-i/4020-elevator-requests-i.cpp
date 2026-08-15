class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int sum=0;
        int curr=0;
        for(int i=0;i<requests.size();i++){
            sum+=(abs(curr-requests[i]));
            curr=requests[i];
        }
        return sum;
    }
};