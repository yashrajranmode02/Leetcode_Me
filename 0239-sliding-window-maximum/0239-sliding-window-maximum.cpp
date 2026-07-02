class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       less<pair<int, int>>>
            pq;
        // index,value.
        unordered_map < int, int >mpp;
        int left = 0;
        int right = 0;
        vector<int> ans;
        while (right < nums.size()) {
            pq.push({nums[right], right});
            mpp[right] = nums[right];
            if (right - left + 1 == k) {
                while(!pq.empty()&&mpp.find(pq.top().second) == mpp.end()){
                    pq.pop();
                }
                if (!pq.empty()&&mpp.find(pq.top().second) != mpp.end()) {
                    ans.push_back(pq.top().first);
                }
               mpp.erase(left);
               left++;

            }
            right++;
        }
        return ans;
    }
};