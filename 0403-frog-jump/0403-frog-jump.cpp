class Solution {
public:
    bool Can_Froggy(int index,int diff,vector<int>& stones,unordered_map<int,int>&mpp,vector<vector<int>>&dp){
            if(index==stones.size()-1){
                return true;
            }
            // if(mpp[index]==0)return false;
            if(dp[index][diff]!=-1)return dp[index][diff];
            int Take=0;int NotTake=0;
            for(int i=diff-1;i<=diff+1;i++){
                if(i<=0)continue;
                int position=stones[index]+i;
                if(mpp.find(position)!=mpp.end()){
                    if(Can_Froggy(mpp[position],i,stones,mpp,dp))return dp[index][diff]=1;
                }
            }
             return dp[index][diff]=0;

    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1||stones.size()==1)return false;
        int n=stones.size();
        unordered_map<int,int>freq;for(int i=0;i<stones.size();i++)freq[stones[i]]=i;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return Can_Froggy(1,1,stones,freq,dp);
    }
};