class Solution {
    long long mod = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        vector< long long> visited(26, -1);
        vector< long long> size(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i] - 'a'] == -1) {
                if (i == 0) {
                    size[i] = 2;
                } else {
                    size[i] = (size[i - 1] * 2)%mod;
                }
            } else {
                if (visited[s[i] - 'a'] == 0) {
                    if (i != 0)
                        size[i] =((( size[i - 1] * 2) - 1)+mod)%mod;
                } else {
                    if (i != 0)
                        size[i] =
                         (( ( 1LL* size[i - 1] * 2) - size[visited[s[i] - 'a'] - 1])+mod)%mod;
                }
            }
            visited[s[i] - 'a'] = i;
        }
        return (size[size.size() - 1] - 1 +mod)%mod;
    }
};