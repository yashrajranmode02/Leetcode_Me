class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        int index = 0;
        while (index < s.size()) {

            while (index < s.size() && s[index] == ' ') {
                index++;
            }
            string temp = "";
            while (index < s.size() && s[index] != ' ') {
                temp += s[index];
                index++;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += ' ';
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == ' '){
            i++;
        }
       string d= ans.substr(i,ans.size()-i+1);
         reverse(d.begin(), d.end());
        return d;
    }
};