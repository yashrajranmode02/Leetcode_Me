class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while (index1 < version1.size() || index2 < version2.size()) {
            string n1 = "", n2 = "";
            while (index1 < version1.size() && version1[index1] == '0') {
                index1++;
            }
            while (index2 < version2.size() && version2[index2] == '0') {
                index2++;
            }
            while (index1 < version1.size() && version1[index1] != '.') {
                n1 += version1[index1];
                index1++;
            }

            while (index2 < version2.size() && version2[index2] != '.') {
                n2 += version2[index2];
                index2++;
            }
            if (n1.size() < n2.size())
                return -1;
            if (n1.size() > n2.size())
                return 1;
                if (n1 < n2) return -1;
if (n1 > n2) return 1;
            index1++;
            index2++;
        }
        return 0;
    }
};