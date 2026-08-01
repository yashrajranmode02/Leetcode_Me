class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
    
         string ans="";
         while(n)
         {
            ans+=to_string(n%2);
            n/=2;
         }
        reverse(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++){
            if(ans[i]=='0'){ans[i]='1'; }
            else {ans[i]='0';} 
         }
         int m=0,index=0;
         for(int i=ans.size()-1;i>=0;i--){
            m+=(ans[i]-'0')*(pow(2,index));
            index++;
         }
         return m;
    }
};