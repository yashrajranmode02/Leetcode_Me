class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && st.top() > num[i] && k) {
                k--;
                st.pop();
            } 
            st.push(num[i]);
        }
        while (!st.empty()  && k) {
            k--;
            st.pop();
        }

        string an = "";
        while (!st.empty()) {
            an += st.top();
            st.pop();
        }
        string p = "";
        int i = an.size() - 1;
        while (i >= 0) {
            if (an[i] == '0') {
                i--;
            } else {
                break;
            }
        }
        while (i >= 0) {
            p += an[i];
            i--;
        }
        // reverse(p.begin(),p.end());
        if (p.empty())
            return "0";
        return p;
    }
};