class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<=end){
            if(!isalnum(s[start])){
                start++;
            }
            else if(!isalnum(s[end])){
                end--;
            }
            else {
               s[start]= tolower(s[start]);
               s[end]=tolower(s[end]);
                if(s[start]==s[end]){
                start++;end--;
                 }
                 else{
                    return 0;
                 }
            } 
        }
        return 1;
    }
};