class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==" "||s.size()==1)return 1;
        int left = 0;
        int right = 0;
        int maxi = 0;
        unordered_map<char, int> mpp;
        int n = s.size();
        while (right < n) {
            if (mpp.find(s[right]) != mpp.end()&&left<=right) {
                maxi = max(maxi,right - left);
                while (mpp.find(s[right]) != mpp.end()) {
                    mpp[s[left]]--;
                    if (mpp[s[left]] == 0) {
                        mpp.erase(s[left]); 
                    }
                    left++;
                }
            }
            mpp[s[right]] = 1;
            right++;
        }
           maxi = max(maxi,right - left);
        return maxi;
    }
};