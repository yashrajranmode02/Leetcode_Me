class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int index1=0;int index2=0;
             int n = s.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for(int index1=s.size()-1;index1>=0;index1--){
            for(int index2=t.size()-1;index2>=0;index2--){
               
                 if(s[index1]==t[index2]){
                     curr[index2]=1+next[index2+1];
                }
                else{
                     int l=0,r=0;
                    l=next[index2];
                    r=curr[index2+1];
                     curr[index2]=max(l,r);
                } 
                
            }
            next=curr;
        }
        return curr[0];
       
    }
};