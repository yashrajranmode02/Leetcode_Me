class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t)return s;
        int n=s.length();int m=t.length();
        string ans="";string temp="";
        int i=0,j=0;int start=0;int end=0;int count=m;
        vector<int>freq(128,0); vector<int>Window_freq(128,0);
        for(int i=0;i<m;i++)freq[t[i]]++;
        
        while(i<n&&j<n){
            
            Window_freq[s[j]]++;
             if(freq[s[j]]>0&&Window_freq[s[j]]<=freq[s[j]]){
                        count--;
                    } 
            if(count==0){
                start=i;
                while(i<=j&&count==0){
                    Window_freq[s[i]]--;
                    if(freq[s[i]]>0&&Window_freq[s[i]]<freq[s[i]]){
                        count++;
                    } 
                    i++;
                }
                if(i-1>=0&&start!=i){
                     if(temp.empty()||temp.size()>(j-(i-1)+1)){
                        temp=s.substr(i-1,j-(i-1)+1);
                    }
                   
                }
                
                
            }
            j++;
        }
        ans=temp;
        return ans;
        
    }
};