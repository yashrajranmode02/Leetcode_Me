// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()<=1)return nums.size();
//         sort(nums.begin(),nums.end());
//         int prev=nums[0];
//         int calci=1;
//         int maxi=0;
//         for(int i=1;i<nums.size();i++){
//              if(nums[i]==prev+1){
//                 calci++;a
//                 prev=nums[i];
//              }
//              else if(nums[i]==prev){
//                 continue;
//              }
//              else{
//                 maxi=max(maxi,calci);
//                 prev=nums[i];calci=1;
//              }
//         }
//          maxi=max(maxi,calci);
//         return maxi;
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int longest=1;
        int n=nums.size();
        if(n==0)return 0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                longest=max(longest, cnt);
            }
        }
        return longest;

    }

};