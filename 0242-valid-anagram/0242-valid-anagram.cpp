class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq1(26,0);
        for(auto it:s){
            freq1[it-'a']++;
        }
        for(auto it:t)freq1[it-'a']--;
        for(auto it:freq1)if(it!=0)return false;
        return true;
    }
};