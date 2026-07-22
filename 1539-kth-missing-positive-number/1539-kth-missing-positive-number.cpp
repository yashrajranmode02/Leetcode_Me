class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;for(int i=0;i<arr.size();i++)mpp[arr[i]]++;
        for(int i=1;i<=1e4;i++){
            if(mpp.find(i)==mpp.end()){
                k--;
                if(k==0)return i;
            }
        }
        return -1;
    }
};