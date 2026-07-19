class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int>mpp;
        for(int i=0;i<bannedWords.size();i++){
            mpp[bannedWords[i]]++;
        }
        int count=0;for(int i=0;i<message.size();i++){
            if(mpp.find(message[i])!=mpp.end()){
                count++;
            }
        }
        return count>=2;
    }
};