class Solution {
public:
    bool sorted(string &s){
        for(int i=1;i<s.size();i++){
            if(s[i] < s[i-1]) return false;
        }
        return true;
    }

    int minOperations(string s) {
    if (sorted(s))return 0;
    if(s.size()==2)return -1;
    char mini=*min_element(s.begin(),s.end());
    char maxi=*max_element(s.begin(),s.end());
    if(s[0]==mini||s[s.size()-1]==maxi){
        return 1;
    }
    else if(s[0]==maxi&&s[s.size()-1]==mini){
        bool p=0;bool q=0;
        for(int i=1;i<=s.size()-2;i++){
            if(mini==s[i]){
                p=1;
            }
            if(maxi==s[i]){
                q=1;
            }
        }
        if(!p&&!q)return 3;
        
    
    }
    return 2;
    }
};